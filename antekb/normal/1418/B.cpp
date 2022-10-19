//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi V(n), czy(n), T;
        for(int i=0; i<n; i++){
            cin>>V[i];
        }
        for(int i=0; i<n; i++){
            cin>>czy[i];
            if(!czy[i])T.pb(V[i]);
        }
        sort(all(T));
        for(int i=0; i<n; i++){
            if(!czy[i]){
                V[i]=T.back();
                T.pop_back();
            }
        }
        /*int j=-1;
        ll sum=0;
        for(int i=0;i<n; i++){
            sum+=V[i];
            if(sum<0)j=i;
        }
        cout<<j+1**/
        for(int i=0; i<n;i ++)cout<<V[i]<<" ";
        cout<<"\n";
    }
}