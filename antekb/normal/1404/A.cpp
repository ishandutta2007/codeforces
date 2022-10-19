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
        int n, k;
        cin>>n>>k;
        vector<int> V;
        for(int i=0; i<n;i++){
            char c;
            cin>>c;
            if(c=='?')V.pb(2);
            else V.pb(c-'0');
        }
        for(int i=k; i<n; i++){
            if(V[i]==2 && V[i-k]!=2)V[i]=V[i-k];
        }
        for(int i=n-k-1; i>=0; i--){
            if(V[i]==2 && V[i+k]!=2)V[i]=V[i+k];
        }
        bool b=0;
        for(int i=k; i<n; i++){
            if(V[i]!=V[i-k]){
                b=1;
                break;
            }
        }
        if(b){
            cout<<"NO\n";
            continue;
        }
        int x=0, y=0;
        for(int i=0; i<k; i++){
            if(V[i]==0)x++;
            else if(V[i]==1)y++;
        }
        if(abs(x-y)<=k-x-y)cout<<"YES\n";
        else cout<<"NO\n";
    }
}