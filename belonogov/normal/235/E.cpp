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
const int N = 2222;
const long long INF = 1e9 + 19;
const int BASE = 26;
//const int SZ = 1 << BASE;
//const int MOD = SZ - 1;


int a, b, c;
vector < int > pr;
int lp[N];
int mx;
long long table[N];
int res[N];

void read() {
    scanf("%d%d%d", &a, &b, &c);
}

long long code(int a, int b, int c, int t) {
    return (((a * mx + b) * 1ll * mx + c) * 1ll * mx + t);
}

unordered_map < long long, int > q;

int f(int a, int b, int c, int t) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    long long hash = code(a, b, c, t); 
    if (t >= (int)pr.size()) return 1;
    int p = pr[t];   
    if (a < p) a = 1;
    if (b < p) b = 1;
    if (c < p) c = 1;
    if (p > a && p > b && p > c) return 1;
    if (q.count(hash) == 0) {
        int sum = 0;
        for (int i = 0, da = 1; da <= a; da *= p, i++) 
            for (int j = 0, db = 1; db <= b; db *= p, j++) 
                for (int k = 0, dc = 1; dc <= c; dc *= p, k++) {
                    sum += f(a / da, b / db, c / dc, t + 1) * (i + j + k + 1); 
                }
        q[hash] = sum;
    }
    return q[hash];
}

void solve() {
    q.reserve(5* 1000 * 1000);
    mx = max(max(a, b), c);
    mx++;
    for (int i = 2; i <= mx ; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < (int)pr.size() && lp[i] >= pr[j] && i * pr[j] <= mx; j++)
            lp[i * pr[j]] = pr[j];
    } 
    //db(pr.size());
    //set < int > tmp;
    //for (auto x: pr)
        //tmp.insert(2000 / x);
    //db(tmp.size());


    int answer = f(a, b, c, 0);  
    //db(q.size());
    answer &= (1 << 30) - 1;
    printf("%d\n", answer);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
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