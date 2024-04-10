#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 2e5 + 7;
int a[MAXN];
bool used[MAXN];
int ste[MAXN];
int cnt = 0;
int mod;
ll res = 1;

int binpow(int a, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return a;
    } else if (n % 2 == 0) {
        int t = binpow(a, n / 2);
        return (t * (ll) t) % mod;
    } else {
        int t = binpow(a, n - 1);
        return (a * (ll) t) % mod;
    }
}

void cycle(int s) {
    if (used[s]) return;
    int w = cnt;
    while (!used[s]) {
        ste[s] = cnt;
        used[s] = 1;
        s = a[s];
        cnt++;
    }
    int len = (ste[s] >= w ? cnt - ste[s] : 0);
    int f = max(0, (cnt - w - len));
    int t = (len ? binpow(2, len) - 2 : 1);
    t = (t % mod + mod) % mod;
    res = (res * (ll) t) % mod;
    t = binpow(2, f);
    res = (res * (ll) t) % mod;
}



int main() {
    mod = (int) 1e9 + 7;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        --a[i];
    }
    for (int i = 0; i < n; i++) {
        cycle(i);
    }
    printf("%lld\n", res);
}