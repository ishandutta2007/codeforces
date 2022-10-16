#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

ll n;

vector<ll> graph[100001];
vector<ll> cnt(100001);

void nn(ll s, ll e) {
    cnt[s] = 1;
    for(ll u: graph[s]) {
        if (u == e) continue;

        nn(u, s);

        cnt[s] += cnt[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t; cin >> t;

    f0r(x, t) {

        cin >> n;

        f0r(i, n+1) {
            graph[i].clear();
        }

        ll u, v;

        vector<pair<ll, ll> > egs;

        f0r(i, n-1) {
            cin >> u >> v;

            graph[u].pb(v);
            graph[v].pb(u);
            cnt[u] = 1;
            cnt[v] = 1;

            egs.pb(mp(u, v));
        }

        nn(1, 0);

        vl st;

        for (pll p: egs) {
            u = p.f; v = p.s;

            st.pb(((n - min(cnt[u], cnt[v])) * min(cnt[u], cnt[v])));
        }

        sort(st.begin(), st.end());


        ll m; cin >> m;

        vl ve(m);

        f0r(i, m) {
            cin >> ve[i];
        }

        while (ve.size() < n - 1) {
            ve.pb(1);
        }

        sort(ve.begin(), ve.end());
        while(ve.size() > n-1){
            ll val = ve.back();
            ve.pop_back();
            ve[(ve).size() - 1] *= val;
            ve[(ve).size() - 1] %= mod;
        }

        //ao(st, n-1);

        ll ret = 0;

        f0r(i, n-1) {
            //cout << ve[ve.size() - i - 1] << " " << st[st.size() - i - 1] << endl;
            ret = (ret + ((ve[ve.size() - i - 1] * st[st.size() - i - 1])) % mod) % mod;
        }

        cout << (ret % mod) << endl;

    }



}