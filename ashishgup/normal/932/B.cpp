#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int f[N], g[N];
int ans[N][10];

int getprod(int k)
{
	int ans=1;
	while(k>0)
	{
		int cur=k%10;
		if(cur>0)
			ans*=cur;
		k/=10;
	}
	return ans;
}

void precompute()
{
	for(int i=1;i<=1e6;i++)
	{
		f[i]=getprod(i);
	}
	for(int i=1;i<=9;i++)
	{
		g[i]=f[i];
	}
}

int dp(int k)
{
	if(k<10)
		return k;
	if(g[k])
		return g[k];
	g[k]=dp(f[k]);
}

int32_t main()
{
    IOS;
    precompute();
    for(int i=1;i<=1e6;i++)
    	dp(i);
    for(int i=1;i<=9;i++)
    {
    	for(int j=1;j<=1e6;j++)
    	{
    		ans[j][i]=ans[j-1][i] + (g[j]==i);
    	}
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int l, r, k;
    	cin>>l>>r>>k;
    	int finans=ans[r][k] - ans[l-1][k];
    	cout<<finans<<endl;
    }
    return 0;
}