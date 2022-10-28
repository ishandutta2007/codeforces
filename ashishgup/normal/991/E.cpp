#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

const int N=20;

int fact[N];

void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
    }
}

int n, finans=0;
int f[N], shouldbe[N];
string s;
set<int> taken;

int32_t main()
{
	IOS;
	precompute();
	cin>>s;
	for(auto it:s)
		shouldbe[it-'0']++;
	n=s.size();
	for(int i=1;i<(1LL<<n);i++)
	{
		memset(f, 0, sizeof(f));
		int len=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				f[s[j]-'0']++;
				len++;
			}
		}
		int ans=fact[len];
		int hash=0, check=1;
		for(int j=0;j<=9;j++)
		{
			if(shouldbe[j] && !f[j])
			{
				check=0;
				break;
			}
			hash=hash*19 + f[j];
			ans/=fact[f[j]];
		}
		if(!check)
			continue;
		if(taken.find(hash)!=taken.end())
			continue;
		taken.insert(hash);
		if(f[0]>=1)
		{
			int cur=f[0];
			f[0]--;
			int curans=1;
			curans*=fact[len-1];
			for(int j=0;j<=9;j++)
			{
				curans/=fact[f[j]];
			}
			ans-=curans;
		}
		finans+=ans;
	}
	cout<<finans;
}