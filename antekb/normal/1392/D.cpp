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
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        int n;
        string t;
        cin>>n;
        cin>>t;
        int a=1;
        vector<int> V;
        for(int i=1; i<n; i++){
            if(t[i]==t[i-1])a++;
            else{ V.pb(a);a=1;}
        }
        if(!V.size()){
            cout<<(n+2)/3<<"\n";
            continue;
        }
        if(t[0]==t[n-1] && V.size())V[0]+=a;
        else V.pb(a);
        ll ans=0;
        for(int i:V){
            //cout<<i<<" ";
            ans+=i/3;
        }
        cout<<ans<<"\n";
    }
}