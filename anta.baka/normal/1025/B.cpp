#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;
using ull = unsigned long long;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 1e6;
const int mod = 998244353;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    ull d = 0;
    int a0 = -1, b0;
    for(int i = 0; i < n; i++) {
        ull a, b; cin >> a >> b;
        if(a0 == -1) a0 = a, b0 = b;
        if(d == 0) d = a / __gcd(a, b) * b;
        else d = __gcd(d, a / __gcd(a, b) * b);
    }
    if(d == 1) return cout << -1, 0;
    for(int i = 2; 1LL * i * i <= a0; i++)
        if(a0 % i == 0) {
            if(d % i == 0) return cout << i, 0;
            while(a0 % i == 0) a0 /= i;
        }
    if(a0 != 1 && d % a0 == 0) return cout << a0, 0;
    for(int i = 2; 1LL * i * i <= b0; i++)
        if(b0 % i == 0) {
            if(d % i == 0) return cout << i, 0;
            while(b0 % i == 0) b0 /= i;
        }
    if(b0 != 1 && d % b0 == 0) return cout << b0, 0;
    assert(false);
}