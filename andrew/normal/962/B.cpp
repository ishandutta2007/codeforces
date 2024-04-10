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
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n >> a[0] >> a[1];
   for(i = 1; i <= n; i++){
        cin >> cc;
        if(cc == '.')b[i] = 1;
   }
   c[0] = a[0];
   c[1] = a[1];
ll   uk = 0;
   for(i = 1; i <= n; i++)if(b[i] == 1){
        if(c[uk % 2] > 0)c[uk % 2]--;
        uk++;
   }else{
        if(c[uk % 2] < c[(uk + 1) % 2])uk++;
   }
   uk = 0;
   ans = a[0] + a[1] - (c[0] + c[1]);
   c[0] = a[1];
   c[1] = a[0];
    for(i = 1; i <= n; i++)if(b[i] == 1){
        if(c[uk % 2] > 0)c[uk % 2]--;
        uk++;
   }
   else{
        if(c[uk % 2] < c[(uk + 1) % 2])uk++;
   }
   ans = max(ans, a[0] + a[1] - c[0] - c[1]);
   vout(ans);
    return 0;
}