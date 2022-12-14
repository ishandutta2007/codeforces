#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    vector <ll> c(51);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> c[i];
    vector < vector<ll> > b(51);
    vector <ll> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c[i]; j++){
            ll x;
            cin >> x;
            b[i].p_b(x);
            s.p_b(x);
        }
    }
    sort(all(s));
    vector <pair <pll, pll> > ans;
    ll sg = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < c[i]; j++, sg++){
            for(int i1 = 1; i1 <= n; i1++)
            for(int j1 = 0; j1 < c[i1]; j1++)if(b[i1][j1] == s[sg] && (i1 != i || j1 != j)){
                ans.p_b({{i, j + 1}, {i1, j1 + 1}});
                swap(b[i][j], b[i1][j1]);
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)cout  << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se.fi << " " << ans[i].se.se << "\n";
    return 0;
}