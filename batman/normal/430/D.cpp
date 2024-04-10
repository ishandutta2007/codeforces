  ///////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                 Sa1378 Platform Vesion 1.3.7.2
/////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


// Don't push me
	// Cause I'm close to the edge
		// I'm trying not to lose my head


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cout << #x << " is " << x << endl;
#define N (1100)
#define ll long long
#define ld long double
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define sin(a) sin(a*PI/180)
#define tan(a) tan(a*PI/180)
#define cot(a) cot(a*PI/180)
#define cos(a) cos(a*PI/180)
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll BIG_HSH=((ll)9999999900000001);
const ll SML_HSH=((ll)100030001);
inline ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ld tavan(ld a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll gcd(ll a,ll b){while(b ^= a ^= b ^= a = a % b);return a;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,a[N][N],dp[4][N][N],ans;

int Sa1378
{
	IB
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
	for(int i=n;i>0;i--)for(int j=1;j<=m;j++)dp[1][i][j]=max(dp[1][i+1][j],dp[1][i][j-1])+a[i][j];
	for(int i=1;i<=n;i++)for(int j=m;j>0;j--)dp[2][i][j]=max(dp[2][i-1][j],dp[2][i][j+1])+a[i][j];
	for(int i=n;i>0;i--)for(int j=m;j>0;j--)dp[3][i][j]=max(dp[3][i+1][j],dp[3][i][j+1])+a[i][j];
	//cout<<dp[0][2][2]<<" "<<dp[1][2][2]<<" "<<dp[2][2][2]<<" "<<dp[3][2][2]<<"\n";
	for(int i=2;i<n;i++)for(int j=2;j<m;j++)ans=max(ans,max(dp[0][i-1][j]+dp[1][i][j-1]+dp[2][i][j+1]+dp[3][i+1][j],dp[0][i][j-1]+dp[1][i+1][j]+dp[2][i-1][j]+dp[3][i][j+1]));
	cout<<ans;	
    return 0;
}