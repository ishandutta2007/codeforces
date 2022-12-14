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
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
bool check(ll x){
    ll le  = a1, ri = b1 , ce  = c1;
    if(le < x && x - le > ce)return 0;
    if(le < x)ce -= x - le;
    if(ri < x && x - ri > ce)return 0;
    return 1;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a1 >> b1 >> c1;
    ll l = 0, r = 1e9;
    while(l < r){
            ll c = (l + r) / 2;
            if(c == l)c++;
            if(!check(c))r = c - 1;else l = c;
    }
    vout(l * 2);
    return 0;
}