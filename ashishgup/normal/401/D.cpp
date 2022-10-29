
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=20;

int n, m;
int f[11];
vector<int> v;
int dp[1<<18][100];
int fact[N];

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
	}
}

void work(int k)
{
	while(k>0)
	{
		v.push_back(k%10);
		f[k%10]++;
		k/=10;
	}
	n=v.size();
}

/*int dp(int mask, int rem)
{
	if(1+mask==(1<<n))
		return (rem==0);
	int &ans=cache[mask][rem];
	if(ans!=-1)
		return ans;
	ans=0;
	if(mask==0)
	{
		for(int i=0;i<n;i++)
		{
			if(v[i]==0 || (mask>>i)&1)
				continue;
			int cur=v[i];
			ans+=dp(mask|(1<<i), (rem*10+cur)%m);
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if((mask>>i)&1)
				continue;
			int cur=v[i];
			ans+=dp(mask|(1<<i), (rem*10+cur)%m);
		}
	}
	return ans;
}*/

int32_t main()
{
	IOS;
	precompute();
	cin>>n>>m;
	work(n);
	for(int rem=0;rem<m;rem++)
		dp[(1<<n)-1][rem]=(rem==0);
	for(int mask=(1<<n)-2;mask>=0;mask--)
	{
		for(int rem=0;rem<m;rem++)
		{
			int &ans=dp[mask][rem];
			if(mask==0)
			{
				for(int i=0;i<n;i++)
				{
					if(v[i]==0 || (mask>>i)&1)
						continue;
					int cur=v[i];
					ans+=dp[mask|(1<<i)][(rem*10+cur)%m];
				}
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if((mask>>i)&1)
						continue;
					int cur=v[i];
					ans+=dp[mask|(1<<i)][(rem*10+cur)%m];
				}
			}
		}
	}
	int ans=dp[0][0];
	for(int i=0;i<=9;i++)
		ans/=fact[f[i]];
	cout<<ans;
	return 0;
}