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

const int N=50, INF=1e9+5, mod=1e9+7;
//int dp[N][N];
int main(){
    int n;
    cin>>n;
    vi V(n);
    for(int &i:V)cin>>i;
    for(int i=2; i<n; i++){
        if(((V[i]^V[i-1])<V[i-2]) || ((V[i-2]^V[i-1])>V[i])){
            cout<<1;
            return 0;
        }
    }
    //cout<<"a";
    int ans=INF;
    //dp[1][0]=V[1];
    for(int i=0; i<n-1; i++){
        int l=V[i];
        for(int j=0; j<=i+1; j++){
            int t=V[i+1];
            for(int k=0; k+i+1<n; k++){
                if(t<l)ans=min(ans, k+j);
                if(k+i+1<n)t^=V[k+i+2];
            }
            if(i!=j)l^=V[i-j-1];
        }
    }
    if(ans==INF)cout<<-1;
    else cout<<ans;
}