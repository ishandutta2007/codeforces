#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=32622780;
const int M=53;
const int MOD=1e9+7;

int n, k, ans=0, sz;
int dp[M][M], largest[N], store[2*M], cnt[M];
map<int, int> idx;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void work(vector<int> &v, vector<pair<int, int> > &div, int n)
{
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
			if(n/i != i)
				v.push_back(n/i);
		}
	}
	sort(v.begin(), v.end());
	sz=v.size();
	for(int i=2;i*i<=n;i++)
	{
		int cnt=0;
		while(n%i==0)
		{
			cnt++;
			n/=i;
		}
		if(cnt>0)
			div.push_back({i, cnt});
	}
	if(n>1)
		div.push_back({n, 1});
	sz=div.size();
}



int32_t main()
{
	IOS;
	cin>>n>>k;
	vector<int> v;
	vector<pair<int, int> > div;
	work(v, div, n);
	for(int i=1;i<=100;i++)
		store[i]=modinv(i);
	for(int j=0;j<=51;j++)
	{
		dp[j][j]=1;
		for(int i=1;i<=k;i++)
		{
			int suf=0;
			for(int k=j;k>=0;k--)
			{
				suf+=dp[j][k]*store[k+1];
				suf%=MOD;
				dp[j][k]=suf;
			}
		}
	}
	for(auto &it:v)
	{
		memset(cnt, 0, sizeof(cnt));
		int num=it;
		for(int i=0;i<sz;i++)
		{
			while(num%div[i].first==0)
			{
				num/=div[i].first;
				cnt[i]++;
			}
		}
		int cur=it%MOD;
		for(int i=0;i<sz;i++)
		{
			cur*=dp[div[i].second][cnt[i]];
			cur%=MOD;
		}
		ans+=cur;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}