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
    int n;
    cin>>n;
    vi V, V2;
    int x;
    cin>>x;
    V2.pb(x);
    V.pb(1);
    for(int i=1; i<n; i++){
        int x;
        cin>>x;
        if(V2.back()==x)V.back()++;
        else{
            V2.pb(x);
            V.pb(1);
        }
    }
    int ans=sz(V);
    for(int i:V)if(i>1)ans++;
    for(int i=1; i<sz(V)-1; i++){
        if(V[i]==1 && V2[i+1]==V2[i-1] && V[i-1]>1){
            while(V[i]==1 && V2[i+1]==V2[i-1]){
                if(V[i+1]>1){ans--; break;}
                else i+=2;
            }
        }
    }
    cout<<ans;
}