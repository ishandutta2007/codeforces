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
const int N = -1;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;
const int T = 3e6;

long long n, m;

void read() {
    scanf("%lld%lld", &n, &m);
}

int solve() {
    long long ans = 0;
    for (long long a = 0; a < T; a++) {
        long long l, r;
        r = (a == 0)? m: min(n / a, m);
        l = (n / (a + 1)) + 1;
        //db2(l, r);
        if (r < l) continue;
        long long d = n % l;
        //db2(r - l, a);
        //db(d);
        assert(d >= (r - l) * a);
        ans = (ans + d % MOD * ((r - l + 1) % MOD)) % MOD;
        long long x1 = (r - l);
        long long x2 = (r - l + 1);
        if (x1 % 2 == 0) x1 /= 2; else x2 /= 2;
        x1 %= MOD;
        x2 %= MOD;
        ans = (ans - x1 % MOD * x2 % MOD * a % MOD + MOD) % MOD;
    }
    for (long long i = min(m, n / T); i >= 1; i--) 
        ans = (ans + n % i) % MOD; 

    return ans;
}

int stupid() {
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + n % i) % MOD; 

    return ans;
}

void genTest() {
    int T = 1e5;
    n = rand() % T + 1;
    m = rand() % T + 1;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        int r1 = solve();
        int r2 = stupid();
        if (r1 != r2) {
            db2(r1, r2);
            db2(n, m);
        }
        assert(r1 == r2);
    }
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
            printf("%d\n", solve());
        }
    }
    else {
        stress();
    }

    return 0;
}