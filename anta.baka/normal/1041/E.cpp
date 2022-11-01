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

const int maxn = 1000;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;

int n, a[maxn], b[maxn], cnt[maxn];
bitset<maxn> in;
vi g[maxn];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(b[i] != n - 1) return cout << "NO", 0;
        cnt[a[i]]++;
    }
    in[n - 1] = 1;
    for(int i = 0; i < n - 1; i++)
        if(cnt[i]) {
            int v = i;
            in[v] = 1;
            for(int j = 0; j < i && cnt[i] > 1; j++) {
                if(!in[j]) {
                    g[v].pb(j);
                    g[j].pb(v);
                    in[j] = 1;
                    v = j;
                    cnt[i]--;
                }
            }
            if(cnt[i] > 1) return cout << "NO", 0;
            g[v].pb(n - 1);
            g[n - 1].pb(v);
        }
    // mb check?
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        for(int j : g[i])
            if(i < j)
                cout << i + 1 << ' ' << j + 1 << '\n';
}