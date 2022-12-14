#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << endl;return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6;
const ll inf = 2e9;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll t[MAXN], ft = 5e5, l[MAXN], r[MAXN], pos[MAXN];

void u(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)t[i] += val;
}

ll f(ll pos){
    ll res = 0;
    for(int i = pos; i > 0; i -= i & -i)res += t[i];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        u(ft + i - 1, 1);
        l[i] = r[i] = i;
        pos[i] = ft + i - 1;
    }

    for(int i = 1; i <= m; i++){
        ll x;
        cin >> x;
        r[x] = max(r[x], f(pos[x]));
        l[x] = 1;
        u(pos[x], -1);
        pos[x] = --ft;
        u(pos[x], 1);
    }

    for(int i = 1; i <= n; i++)r[i] = max(r[i], f(pos[i]));

    for(int i = 1; i <= n; i++)cout << l[i] << " " << r[i] << "\n";

    return 0;
}