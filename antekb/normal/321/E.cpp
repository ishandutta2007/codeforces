#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=4e3+5, INF=1e9+5, mod=1e9+7;
int tab[N][N], tab2[N][N], tab3[N][N], dp[805][N];
void prop(int l, int r, int a ,int b, int k){
    int m=(l+r)/2, skad=m;
    dp[k][m]=dp[k-1][m];
    for(int i=a; i<=b && i<m; i++){
        if(dp[k-1][i]+tab3[i][m]<dp[k][m]){
            skad=i;
            dp[k][m]=dp[k-1][i]+tab3[i][m];
        }
    }
    if(m>l)prop(l, m-1, a, skad, k);
    if(m<r)prop(m+1, r, skad, b, k);
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    char c;
    int n, k;
    scanf("%d %d",&n, &k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            c=0;
            while(c<33) c=getchar();

            tab2[i][j]=tab2[i][j-1]+tab2[i-1][j]-tab2[i-1][j-1]+c-'0';
            //cout<<tab2[i][j]<<" ";
        }
    //cout<<"\n";
    }
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            tab3[i][j]=tab2[j][j]+tab2[i][i]-tab2[j][i]-tab2[i][j];
        }
    }
    //return 0;
    for(int i=0; i<=n; i++){
        dp[0][i]=tab3[0][i];
    }
    for(int i=1; i<k; i++){
        prop(1, n, 0, n, i);
    }
    cout<<dp[k-1][n]/2;
}