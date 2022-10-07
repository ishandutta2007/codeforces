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

int a;
char s[N];
int cnt[N];
int n;

void read() {
    scanf("%d", &a);
    scanf("%s", s);
    n = strlen(s);
    for (int l = 0; l < n; l++) {
        int sum = 0;
        for (int r = l + 1; r <= n; r++) {
            sum += s[r - 1] - '0';
            cnt[sum]++;
        }
    }
} 

int getC(int x) {
    if (x > n * 10) return 0;
    return cnt[x];
}

void solve() {
    long long answer = 0;
    int all = n * (n + 1) / 2;
    if (a == 0) {
        answer = 2 * (all * 1ll * cnt[0]) - cnt[0] * 1ll * cnt[0];
    }
    else {
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                int c = a / i; 
                int cof = 2;
                if (i == c) 
                    cof = 1;
                answer += getC(i) * 1ll * getC(c) * cof;
            }
        }
    }

    printf("%lld\n", answer);
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
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}