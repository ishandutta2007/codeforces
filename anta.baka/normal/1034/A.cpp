#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll
#define NAME ""

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

const int maxn = 2e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;

const int N = (int)2e7;
int p[N], c[N];

inline void go(int n) {
    while(n != 1) {
        int x = p[n];
        c[x]++;
        while(n % x == 0) n /= x;
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    iota(p, p + N, 0);
    for(int i = 2; i * i < N; i++)
        if(p[i] == i)
            for(int j = i * i; j < N; j += i)
                p[j] = i;
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int g = a[0];
    for(int i = 1; i < n; i++) g = __gcd(g, a[i]);
    for(int i = 0; i < n; i++) {
        a[i] /= g;
        go(a[i]);
    }
    int ans = n;
    for(int i = 2; i < N; i++) ans = min(ans, n - c[i]);
    cout << (ans == n ? -1 : ans);
}