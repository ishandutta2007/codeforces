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

struct{
    ll p[2],kl;
}b[10000001];
vector <ll> v[MAXN],va;
string s2,s3;
multiset <ll> s;
set <ll> s1;
char cc;
ll a[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll qq = 1;
void addB(ll x, ll val){
    ll q = 0, i;
    for(i = 30; i >= 0; i--){
        ll pe = ((1ll << i)& x);
        if(pe > 0)pe = 1;
        //cout << x << " " << pe << " " << i << endl;
        if(!b[q].p[pe])b[q].p[pe] = qq++;
        q = b[q].p[pe];
        b[q].kl += val;
    }
}
ll add(ll x){
    ll q = 0, res = 0, i;
    for(i = 30; i >= 0; i--){
        ll pe = ((1ll << i)&x);
        if(pe > 0)pe = 1;
        ll xx = (1ll<<i);
        if(!pe)xx=0;
        //if(x == 8)cout << b[q].p[pe] << " " << pe << " " << xx << " " << i << endl;
        if(b[q].p[pe] && b[b[q].p[pe]].kl){
            q = b[q].p[pe];
            res |= xx;
        }else {
           if(!pe)pe = 1;else pe = 0;
           xx = (1ll<<i);
           if(!pe)xx = 0;
           //if(x == 8)cout << "2: " << b[q].p[pe] << " " << pe << " " << xx << " " << i << endl;
           //cout << xx << " " << i << endl;
           res |= xx;
           q = b[q].p[pe];
        }
    }
    return res;
}
    int main(){
    multiset <ll> :: iterator it,it1;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(i = 1; i <= n; i++){
        cin >> x;
        addB(x,1);
    }
    for(i = 1; i <= n; i++){
        m = a[i];
        x = add(m);
        addB(x, -1);
        cout << (x ^ m) << " ";
    }
    cout << endl;
    return 0;
}