#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=2e5+5, INF=2e9+5, mod=998244353;
int A[N], B[N], pocz[N], kon[N];
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>A[i];
    }
    for(int i=0; i<m; i++){
        cin>>B[i];
    }
    int wsk=m-1;
    for(int i=n; i>0;){
        //cout<<wsk<<" ";
        if(A[i]==B[wsk] && kon[wsk]==0){
            kon[wsk]=i;
        }
        if(A[i]<B[wsk]){
            pocz[wsk]=i+1;
            wsk--;
            if(wsk<0){
                cout<<0;
                return 0;
            }
            continue;
        }
        i--;
    }
    if(wsk==0) pocz[0]=1;
    for(int i=0; i<m; i++){
        //cout<<pocz[i]<<" "<<kon[i]<<"\n";
        if(pocz[i]==0 || kon[i]==0 || pocz[i]>kon[i]){
            cout<<0;
            return 0;
        }
    }
    int res=1;
    for(int i=1; i<m; i++){
        res=(res*1ll*(kon[i]-pocz[i]+1))%mod;
    }
    cout<<res;
}