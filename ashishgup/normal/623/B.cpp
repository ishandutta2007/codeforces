#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int INF=1e15;

int n, a, b;
int v[N];
set<int> primes;

void generate(int x)
{
	if(x%2==0)
	{
		primes.insert(2);
		while(x%2==0)
			x/=2;
	}
	for(int i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
		{
			primes.insert(i);
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1)
	{
		primes.insert(x);
	}
}


int32_t main()
{
    IOS;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
    	cin>>v[i];
    }
    int ans=INF;
    generate(v[1]-1);
    generate(v[1]);
    generate(v[1]+1);
    generate(v[n]-1);
    generate(v[n]);
    generate(v[n]+1);
    for(auto p:primes)
    {
    	int dp[n+1][3];
    	dp[0][0]=dp[0][1]=dp[0][2]=0;
    	for(int i=1;i<=n;i++)
    	{
    		dp[i][0]=dp[i][1]=dp[i][2]=INF;
    		int cur_rem=v[i]%p;
    		if(cur_rem==0)
    		{
    			dp[i][0]=dp[i-1][0];
    			dp[i][1]=min(dp[i-1][0], dp[i-1][1]) + a;
    			dp[i][2]=min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
    		}
    		else if(cur_rem==1||cur_rem==p-1)
    		{
    			dp[i][0]=dp[i-1][0]+b;
    			dp[i][1]=min(dp[i-1][0], dp[i-1][1]) + a;
    			dp[i][2]=min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + b;
    		}
    		else
    		{
    			dp[i][1]=min(dp[i-1][0], dp[i-1][1]) + a;
    		}
    	}
    	ans=min(ans, dp[n][0]);
    	ans=min(ans, dp[n][1]);
    	ans=min(ans, dp[n][2]);
    }
    cout<<ans;
    return 0;
}