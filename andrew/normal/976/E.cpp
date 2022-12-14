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

vector <ll> v[MAXN],va;
string s1,s2,s3;
multiset <ll> s;
set <pll> ss;
char cc;
pll a[MAXN];
bool f[MAXN];
ll c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> a1 >> b1;
    ll k = 1ll << a1;
    for(i = 1; i <= n; i++)cin >> a[i].fi >> a[i].se;
    for(i = 1; i <= n; i++)ans += a[i].se;
    for(i = 1; i <= n; i++)ss.insert(m_p(a[i].fi - a[i].se, i));
    set <pll> :: iterator it;
    while(ss.size() && (ss.size() > b1 or (ss.begin())->fi < 1)){
        it = ss.begin();
        f[it->se] = 1;
        ss.erase(it);
    }
    ll res = ans;
   if(b1 == 0)vout(res);
  // cout << ans << endl;
   if(ss.size()){
        it = ss.begin();
        for(; it != ss.end(); ++it){
            ans += it -> fi;
        }
   }
    res = max(res, ans);
    if(ss.size())it = ss.begin();
    for(i = 1; i <= n; i++){
        ll a1 = ans;
        if(f[i]){
            if(ss.size() && ss.size() == b1)a1 -= it -> fi;
            a1 += a[i].fi * k - a[i].se;
        }else{
            a1 += a[i].fi * k - a[i].se - a[i].fi + a[i].se;
        }
       // cout << a1 << endl;
        res = max(res, a1);
    }
    cout << res << endl;
    return 0;
}