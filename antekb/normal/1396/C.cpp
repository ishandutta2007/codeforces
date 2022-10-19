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
ll tab[N], tab2[N], dp[2][N];
int main(){
    ll n, r1, r2, r3, d;
    cin>>n>>r1>>r2>>r3>>d;
    r1=min(r1, r3);
    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        tab[i]=a*r1+r3;
        tab2[i]=min((a+2)*r1, r2+r1);
        tab2[i]=min(tab[i], tab2[i]);
        //cout<<tab[i]<<" "<<tab2[i]<<"\n";
    }
    //cout<<"\n\n";
    dp[1][0]=1e18;
    for(int i=1; i<=n; i++){
        dp[0][i]=min(dp[0][i-1]+tab[i], dp[1][i-1]+tab2[i]+d);
        if(i==n)dp[0][i]=min(dp[0][i], dp[1][i-1]+tab[i]);
        dp[1][i]=dp[0][i-1]+tab2[i]+d;
        //cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
    }
    cout<<min(dp[0][n], dp[1][n]+d)+d*(n-1);
}