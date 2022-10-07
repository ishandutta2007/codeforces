#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

struct Fraq {
    long long p, q;
    Fraq(long long p, long long q): p(p), q(q) { }
    bool operator < (Fraq A) {
        return p * A.q < A.p * q;
    }
};

int n;
int a[N];
long long pref[N];


vector < int > answer;


long long getSum(int l, int r) {
    return pref[r] - pref[l];
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

Fraq f(int l, int i) {
    long long sum = -getSum(0, l) - a[i] - getSum(i + 1, i + l + 1) + a[i] * 1ll * (l * 2 + 1);
    return Fraq(sum, l * 2 + 1);
}

void calc() {
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    pair < int, int > where = mp(-1, -1);

    Fraq best(-1, 1);
    for (int i = 1; i < n - 1; i++) {
        int l = 0; 
        int c1 = i;
        int c2 = n - i - 1;
        int r = min(c1, c2);
        while (r - l > 5) {
            int m1 = (l + l + r) / 3;
            int m2 = (l + r + r) / 3;
            Fraq r1 = f(m1, i);
            Fraq r2 = f(m2, i);
            if (r1 < r2)
                l = m1;
            else
                r = m2;
        }
        for (int j = l; j <= r; j++) {
            Fraq r1 = f(j, i);
            if (best < r1) {
                where = mp(i, j);
                best = r1;
            }

        }
    }
    if (where.fr != -1) {
        answer.clear();
        for (int i = 0; i < where.sc; i++)
            answer.pb(a[i]);
        for (int i = 0; i <= where.sc; i++)
            answer.pb(a[where.fr + i]);
    }
}

vector < int > solve() {
    if (n <= 2) {
        vector < int > answer;
        answer.pb(a[0]);
        return answer;
    }
    
    for (int i = 0; i < n; i++)
        a[i] *= -1;
    calc();
    return answer;
}

void printAns(vector < int > answer) {
    for (auto &x: answer)
        x = abs(x);
    sort(answer.begin(), answer.end());
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", abs(x)); 
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}