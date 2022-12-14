#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
//#define endl "\n"
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

vector <pll> v[MAXN],va;
string s1,s2,s3;
multiset <ll> s;
multiset <ll> :: iterator it;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
void dfs(ll x, ll pr){
    if(pr){
        it = s.begin();
        c = *it;
        if((sc - c) > a[x]){
            b[x] = 1;
            return;
        }
    }
    s.insert(sc);
    ll i, nn = v[x].size();
    for(i = 0; i < nn; i++)if(v[x][i].fi != pr){
        sc += v[x][i].se;
        dfs(v[x][i].fi, x);
        sc -= v[x][i].se;
    }
    s.erase(s.find(sc));
}
void dfs1(ll x, ll pr){
    if(b[x])return;
    ans++;
    ll i, nn = v[x].size();
    for(i = 0; i < nn; i++)if(v[x][i].fi != pr)dfs1(v[x][i].fi, x);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 2; i <= n; i++){
        cin >> a1 >> b1;
        v[i].p_b(m_p(a1,b1));
        v[a1].p_b(m_p(i,b1));
    }
    dfs(1ll, 0ll);
    //cout << "kek" << endl;
    dfs1(1ll, 0ll);
    vout(n - ans);
    return 0;
}