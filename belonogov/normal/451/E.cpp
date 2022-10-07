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
const int N = 20;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n;
long long s;
long long f[N];

void read() {
    scanf("%d%lld", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%lld", &f[i]);
}

long long R = 1;

long long calc(long long t) {
    if (t < 0) return 0;
    int k = n - 1; 
    long long m = t + n - 1;
    long long res = 1;
    for (int i = 0; i < k; i++)
        res = (res * ((m - i) % MOD)) % MOD;

    res = (res * R) % MOD;
    //db2(t, res);
    return res;
}

long long rev(long long a, long long m) {
    if (a == 0) return 0;
    return ((1 - rev(m % a, a) * m) / a + m) % m;
}

void solve() {
    for (int i = 1; i < n; i++)
        R = (R * i) % MOD;
    R = rev(R, MOD);

    long long answer = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long g = s;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                g -= f[i] + 1;
        int t = (__builtin_popcount(mask) % 2 == 1)? -1: 1;
        answer = (answer + t * calc(g) + MOD) % MOD;
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