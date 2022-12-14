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
set <ll> s;
map <ll, vector <ll>> mp;
char cc;
ll c[MAXN];

ll dp[MAXN];
ll pr[MAXN];
ll a[MAXN],b[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n;
   for(i = 1; i <= n + 1; i++)b[i] = 1e18;
   for(i = 1; i <= n; i++)cin >> a[i];
   for(i = 1; i <= n; i++){
        x = a[i];
        s.insert(x);
        mp[x].p_b(i);
   }
   for(i = 1; i <= n; i++){
        x = a[i];
        if(mp.find(x - 1) == mp.end()){
            dp[i] = 1;
            //cout << i << endl;
            pr[i] = 0;
        }else{
            vector <ll> :: iterator it = lower_bound(all(mp[x - 1]), i);
            if(it == mp[x - 1].begin()){
                dp[i] = 1;
                pr[i] = 0;
            }else{
                --it;
                dp[i] = dp[*it] + 1;
                pr[i] = *it;
            }
        }
   }
   ll mx = -1, mxx = 0;
   for(i = 1; i <= n; i++)if(mx < dp[i]){
        mx = dp[i];
        mxx = i;
   }
   while(mxx != 0){
        v1.p_b(mxx);
        mxx = pr[mxx];
   }
   reverse(all(v1));
   cout << v1.size() << endl;
   for(i = 0; i < v1.size(); i++)cout << v1[i] << " ";
   cout << endl;
    return 0;
}