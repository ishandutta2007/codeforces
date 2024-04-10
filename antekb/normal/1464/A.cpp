#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vi nxt(n+1);
        int ans=0;
        for(int i=0; i<m; i++){
            int x, y;
            cin>>x>>y;
            if(x==y)continue;
            else nxt[x]=y, ans++;
        }
        for(int i=1; i<=n; i++){
            if(nxt[i]==0)continue;
            int j=nxt[i];
            nxt[i]=0;
            while(nxt[j]!=i && nxt[j]!=0){
                int k=nxt[j];
                nxt[j]=0;
                j=k;
            }
            if(nxt[j]==i){
                nxt[j]=0;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}