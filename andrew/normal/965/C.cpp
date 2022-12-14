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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll d;
ll get(ll x){
    ll sc = n / x;
    ll ku = sc / k;
    if(sc % k)ku++;
    return ku;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k >> m >> d;
    ll l = 1, r = min(n, m);
    for(i = 1; i <= d; i++){
            ll l = 1, r = min(n, m);
            while(l < r){
                ll c = (l + r) / 2;
                //cout << l << " " << r << endl;
                if(get(c) >= i)l = c + 1; else r = c - 1;
            }
            if(get(l) < i)l--;
            //cout << l << " " << i << endl;
            ans = max(ans, i * l);
    }
    vout(ans);
    return 0;
}