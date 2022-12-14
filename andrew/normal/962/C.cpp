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

vector <ll> v[MAXN],va, v1;
string s1,s2,s3;
multiset <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll sqq(ll x){
    ll ke = sqrt(x);
    while(sqr(ke) < x)ke++;
    while(sqr(ke) > x)ke--;
    return ke;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n;
   while(n){
        va.p_b(n % 10);
        k++;
        n /= 10;
   }
   ans = 1e18;
   ll m = 1ll << k;
   reverse(all(va));
   for(i = 1; i < m; i++){
        ll ln = 0;
        x = 0;
        for(j = 0; j < k; j++)if(((1ll << j) & i)){
            if(!x && !va[j])continue;
            ln++;
            x = x * 10 + va[j];
        }
        if(x == 0)continue;
        if(sqr(sqq(x)) == x)ans = min(ans, va.size() - ln);
   }
   if(ans == 1e18)vout(-1);
   vout(ans);
    return 0;
}