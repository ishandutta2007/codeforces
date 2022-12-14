#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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

vector <pll> v;
string s1, s2,s3;
map <ll, vector <ll> > mp;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> s1;
        m = s1.size();
        ll mn = 1e18;
        sc = 0;
        for(j = 0; j < m; j++){
            if(s1[j] == '(')sc++; else sc--;
            mn = min(mn, sc);
        }
        a[i] = sc;
        b[i] = mn;
        if(sc == 0 && mn < 0)continue;
        v.p_b(m_p(mn, sc));
    }
    sort(all(v));
    for(i = 0; i < v.size(); ++i)mp[v[i].se].p_b(v[i].fi);
    for(i = 1; i <= n; i++){
        ll mn = b[i], sc = a[i];
        k = -sc;
        if(mn < 0)continue;
        if(mp.find(k) != mp.end())ans += mp[k].size() - (lower_bound(all(mp[k]), -sc) - mp[k].begin());
    }
    cout << ans << "\n";
    return 0;
}