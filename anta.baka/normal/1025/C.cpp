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
    string s; cin >> s;
    string a = s + s;
    reverse(all(s));
    string b = s + s;
    int n = sz(s);
    vi A(2 * n), B(2 * n);
    A[0] = B[0] = 1;
    int ans = 1;
    for(int i = 1; i < 2 * n; i++) {
        A[i] = (a[i - 1] == a[i] ? 1 : 1 + A[i - 1]);
        B[i] = (b[i - 1] == b[i] ? 1 : 1 + B[i - 1]);
        ans = max({ans, A[i], B[i]});
    }
    cout << min(ans, n);
}