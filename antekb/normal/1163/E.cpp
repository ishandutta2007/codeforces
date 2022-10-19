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

const int N=2e5+5, INF=1e9+5, mod=1e9+7, K=20;
int B[K], B2[K];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vi V(n);
    for(int i=0; i<n; i++){
        cin>>V[i];
    }
    sort(all(V));
    fill(B, B+K, -1);
    int b=0, ans=0;
    for(int i=0; i<n; i++){
        int prev=V[i];
        for(int j=0; j<K; j++){
            if((1<<j)&V[i]){
                if(B[j]!=-1)V[i]^=B[j];
                else{
                    B[j]=V[i];
                    B2[j]=prev;
                    b++;
                    int ans2=0, maks=0;
                    for(int k=0; k<b; k++){
                        if(B[k]==-1)break;
                        maks=max(maks, B2[k]);
                        ans2++;
                        if((1<<ans2)>maks)ans=max(ans, ans2);
                    }
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
    int k=0;
    cout<<k<<" ";
    for(int i=1; i<(1<<ans); i++){
        k^=B2[__builtin_ctz(i)];
        cout<<k<<" ";
    }
}