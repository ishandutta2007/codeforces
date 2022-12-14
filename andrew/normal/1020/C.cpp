#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

vector <ll> v[MAXN];
bool fl[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    vector <pll> b(n + 1);
    for(int i = 1; i <= n; i++)cin >> b[i].se >> b[i].fi;
    sort(b.begin() + 1, b.end());
    for(int i = 1; i <= n; i++){
        pll x = b[i];
        v[x.se].p_b(i);
    }
    ll ans = 1e18;
    ll con = v[1].size();
    ll kek = max(1ll, con);
    for(int i = kek; i <= n; i++){
        ll sc = 0, kol = 0;
        kol = con;
        for(int j = 1; j <= n; j++)fl[j] = 0;
        for(int j = 0; j < con; j++)fl[v[1][j]] = 1;
        for(int j = 2; j <= m; j++){
            ll k = 0;
            if(v[j].size() >= i)k = v[j].size() - i + 1;
            for(int i1 = 0; i1 < k; i1++){
                ll pos = v[j][i1];
                sc += b[pos].fi;
                fl[pos] = 1;
                kol++;
            }
        }
        for(int j = 1; j <= n; j++)if(kol < i && !fl[j]){
            kol++;
            sc += b[j].fi;
        }
        ans = min(ans, sc);
    }
    cout << ans << "\n";
    return 0;
}
/*
8 4
2 200
1 0
3 400
3 400
3 400
4 500
4 500
4 500
*/