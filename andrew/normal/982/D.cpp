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

vector <ll> v[MAXN],va;
map <ll, vector <ll> > mp;
set <pll> s;
set <ll> s2;

multiset <ll> s1;
set <ll> se;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
void add(ll x){
    set <pll> :: iterator it;
    it = s.upper_bound(m_p(x, 1e18));
    --it;
    pll xe = *it;
    s.erase(it);
    ll l = xe.fi, r = x - 1;
    s1.erase(s1.find(xe.se - xe.fi + 1));
    if(s1.find(xe.se - xe.fi + 1) == s1.end())se.erase(xe.se - xe.fi + 1);
    if(r >= l){
        s.insert(m_p(l, r));
        s1.insert(r - l + 1);
        se.insert(r - l + 1);
    }
    l = x + 1;
    r = xe.se;
    if(r >= l){
        s.insert(m_p(l, r));
        s1.insert(r - l + 1);
        se.insert(r - l + 1);
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    s.insert(m_p(1, n));
    s1.insert(n);
    se.insert(n);
    for(i = 1; i <= n; i++){
        cin >> a[i];
        x = a[i];
        mp[x].p_b(i);
        s2.insert(x);
    }
    set <ll> :: iterator it = s2.end(), it1 = s2.end();
    --it1;
    ll mx = 1, mxj = *it1 + 1;
    for(; it != s2.begin(); ){
        --it;
        x = *it;
        va = mp[x];
        ll nn = va.size();
        for(i = 0; i < nn; i++)add(va[i]);
        if(se.size() < 2 && s.size() > 0){
            it1 = it;
            --it1;
            ll xx = *it1 + 1;
            if(s.size() > mx){
                mx = s.size();
                mxj = xx;
            }else if(s.size() == mx)mxj = xx;

        }
    }
    vout(mxj);
    return 0;
}