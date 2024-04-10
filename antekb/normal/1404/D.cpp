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

const int N=1e6+5, INF=1e9+5, mod=1e9+7;
vector<int> E[N];
int czy[N], uzy[N];
int main(){
    int n;
    cin>>n;
    if(!(n&1)){
        cout<<"First"<<endl;
        if(n%4==0){
            for(int i=1; i<=n-2; i++){
                cout<<i<<" ";
            }
            cout<<n-1<<" "<<n-1<<" ";
            for(int i=1; i<=n-2; i++){
                cout<<i<<" ";
            }
            cout<<n<<" "<<n<<" ";
        }
        else{
            for(int i=0; i<2*n; i++){
                if(i&1)cout<<2*(i/4)+1<<" ";
                else cout<<2*(i/4)+2<<" ";
            }
        }
        cout<<endl;
        return 0;
    }
    cout<<"Second"<<endl;
    vector<int> kto(n+1);
    for(int i=1; i<=2*n; i++){
        int a;
        cin>>a;
        if(kto[a]==0)kto[a]=i;
        else{
            E[kto[a]].pb(i);
            E[i].pb(kto[a]);
        }

    }
    for(int i=1; i<=n; i++){
        E[i].pb(i+n);
        E[i+n].pb(i);
        //cout<<E[i].size()<<" "<<E[n+i].size()<<" ";
    }

    for(int j=1; j<=2*n; j++){
        if(uzy[j])continue;
        vector<int> V;
        czy[j]=1;
        uzy[j]=1;
        V.pb(j);
        for(int i=0; i<V.size(); i++){
            int v=V[i];
            //cout<<v<<"\n";
            for(int u:E[v]){
                if(!uzy[u]){
                    uzy[u]=1;
                    czy[u]=czy[v]^1;
                    V.pb(u);
                }
            }
        }
    }
    int sum=0;
    for(int i=1; i<=2*n; i++){
        if(czy[i])sum^=(i&1);
    }
    for(int i=1; i<=2*n; i++){
        if(sum^czy[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}