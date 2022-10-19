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

const int N=52, INF=1e9+5, mod=1e9+7;
int dp[N][N][N], opt[N][N][N];
vector<pair<pii, pii> > V2;
int main(){
    int n, m, H;
    cin>>n>>H>>m;
    for(int i=0; i<m; i++){
        int l, r, c, h;
        cin>>l>>r>>h>>c;
        V2.pb(mp(mp(l, r), mp(h, c)));
    }
    for(int h=1; h<=H; h++){
        for(int d=0; d<n; d++){
            for(int l=1; l<=n-d; l++){
                int r=l+d;
                vector<pii> V;
                for(auto a:V2){
                    if(a.st.st>=l && a.st.nd<=r && a.nd.st<h){
                        V.pb(mp(a.st.st, a.nd.nd));
                        V.pb(mp(a.st.nd+1, -a.nd.nd));
                    }
                }
                sort(all(V));
                int wsk=0, c=0;
                for(int i=l; i<=r; i++){
                    while(wsk<V.size() && V[wsk].st==i){
                        c+=V[wsk++].nd;
                    }
                    dp[l][r][h]=max(dp[l][r][h], opt[l][i-1][h-1]+opt[i+1][r][h]+h*h-c);
                }
                opt[l][r][h]=dp[l][r][h];
                if(opt[l][r][h-1]>opt[l][r][h])opt[l][r][h]=opt[l][r][h-1];
                //cout<<l<<" "<<r<<" "<<h<<" "<<dp[l][r][h]<<" "<<opt[l][r][h]<<"\n";
            }
        }
    }
    cout<<opt[1][n][H];
}