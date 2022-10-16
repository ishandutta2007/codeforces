 
#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define lll __int128
#define pb(a) push_back(a)
#define ld long double
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
ll inf = pow(10,9);
const ll modulo = 998244353;
 
#define MAX 1'000'010
bool pr[MAX];
 
void pre(){
      for(ll i = 2; i<MAX; i++){
            pr[i] = 1;
      }
      for(ll i = 2; i<MAX; i++){
            if(pr[i]){
                  for(ll j = 2*i; j<MAX; j+=i){
                        pr[j] = 0;
                  }
            }
      }
}
 
 
void deal(){
      pre();
      ll t;
      cin>>t;
      forl(t){
            ll e, n;
            cin>>n>>e;
            vector<ll> dpl(n, 0), dpr(n, 0);
            vector<ll> arr(n);
            fori(n){
                  cin>>arr[i];
            }
            for(ll i = n-1; i>=0; i--){
                  if(arr[i] == 1){
                        dpr[i] = 1;
                        if(i + e < n){
                              dpr[i] += dpr[i+e];
                        }
                  }
            }
            fori(n){
                  if(arr[i] == 1){
                        dpl[i] = 1;
                        if(i - e >= 0){
                              dpl[i] += dpl[i-e];
                        }
                  }
            }
            ll ans = 0;
            fori(n){
                  ll ed = arr[i];
                  if(pr[ed]){
                        ll lef = 1, rig = 1;
                        if(i - e >= 0){
                              lef = dpl[i-e] + 1;
                        }
                        if(i + e < n){
                              rig = dpr[i+e] + 1;
                        }
                        ans += lef * rig - 1;
                  }
            }
            cout<<ans<<'\n';
      }
}
 
int main(){ 
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
      return 0;
}