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
string s2,s3;
multiset <ll> s;
set <ll> s1;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    multiset <ll> :: iterator it,it1;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i <= n; i++)cin >> b[i];
    ll sc = 0;
    for(i = 1; i <= n; i++){
        s.insert(a[i] + sc);
        s1.clear();
        it = s.upper_bound(b[i] + sc);
        it1 = s.begin();
        ans = 0;
        for(;it != it1; ++ it1){
            x = *it1;
            //if(i == 2)cout << x << " " << sc << endl;
            s1.insert(x);
            ans += x - sc;
        }
        if(s1.size()){
            set <ll> :: iterator itt = s1.begin();
            for(;itt != s1.end(); ++itt)s.erase(*itt);
        }
        ans += b[i] * s.size();
        sc += b[i];
        cout << ans << " ";
    }
    return 0;
}