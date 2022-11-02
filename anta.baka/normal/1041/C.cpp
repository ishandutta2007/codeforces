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

const int maxn = 5e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;

int b[maxn];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    int n, m, d; cin >> n >> m >> d;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].x, a[i].y = i;
    sort(all(a));
    int tot = 1;
    vi ans(n);
    const auto cmp = [&](int i1, int i2) {
        return b[i1] < b[i2];
    };
    multiset<int, decltype(cmp)> setik(cmp);
    b[0] = -d;
    setik.insert(0);
    for(int i = 0; i < n; i++) {
        int id = *setik.begin();
        if(b[id] + d < a[i].x) {
            setik.erase(setik.begin());
            b[id] = a[i].x;
            setik.insert(id);
            ans[a[i].y] = id + 1;
        } else {
            b[tot] = a[i].x;
            setik.insert(tot++);
            ans[a[i].y] = tot;
        }
    }
    cout << tot << '\n';
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}