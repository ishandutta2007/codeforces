#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
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
ll dp[MAXN];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   string s;
   cin >> s;
   sort(all(s));
   ll n = s.size();
   vector <ll> a(n);
   ll mask = 1;
   for(int i = 0; i < n; i++)a[i] = s[i] - '0';
   for(int i = 1; i < n; i++)if(a[i] != a[i - 1])mask |= 1ll << i;
   dp[0] = 1;
   ll res = 0;
   ll m = 1ll << n;
   for(int i = 0; i < m; i++){
     if((i & mask) == mask)res += dp[i];
     
     for(int j = 0; j < n; j++)if(!((1ll << j) & i)){
                             if(i == 0 && a[j] == 0)continue;
                             if(j != 0){
                                                      ll ae = (1ll << j - 1) & i;
                                                      if(ae == 0 && a[j] == a[j - 1])continue;
                             }
                             dp[i | (1ll << j)] += dp[i];
     }
   }
   cout << res << endl;
   return 0;
 }