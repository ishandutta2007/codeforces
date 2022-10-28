#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=205;
const int offset=205;

int n, l, k;
int a[N];
bool vis[N][2*N][N];
double p[N];
double cache[N][2*N][N];

double dp(int idx, int cursz, int won)
{
	if(idx==n+1)
		return (won>=l && cursz>=0);
	double &ans=cache[idx][cursz+offset][won];
	if(vis[idx][cursz+offset][won])
		return ans;
	vis[idx][cursz+offset][won]=1;
	ans=(1-p[idx])*dp(idx+1, cursz, won);
	ans+=p[idx]*dp(idx+1,min(200, (a[idx]+cursz)), won+1);
	return ans;
}

int32_t main()
{
    IOS;
    cin>>n>>l>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>p[i];
    	p[i]/=100;
    }
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    double ans=dp(1, k, 0);
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}