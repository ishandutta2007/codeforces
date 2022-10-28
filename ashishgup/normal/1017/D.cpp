#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e5+5;
const int M=1LL<<12;

int n, m, q;
int w[20], f[M], ans[N];
int store[M][101];

void work()
{
	int maxval=(1<<n) - 1;
	for(int i=0;i<=maxval;i++)
	{
		if(!store[i])
			continue;
		for(int j=0;j<=maxval;j++)
		{
			if(!f[j])
				continue;
			int curval=0;
			for(int k=0;k<n;k++)
			{
				int bit1=(i>>k)&1;
				int bit2=(j>>k)&1;
				if(bit1==bit2)
					curval+=w[n-k];
				if(curval>100)
					break;
			}
			if(curval<=100)
				store[i][curval]+=f[j];
		}
	}
	for(int i=0;i<=maxval;i++)
	{
		for(int j=1;j<=100;j++)
		{
			store[i][j]+=store[i][j-1];
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		string cur;
		cin>>cur;
		int val=0;
		for(auto &it:cur)
			val=val*2 + (it-'0');
		f[val]++;
	}
	work();
	for(int i=1;i<=q;i++)
	{
		string cur;
		cin>>cur;
		int val=0;
		for(auto &it:cur)
			val=val*2 + (it-'0');
		int k;
		cin>>k;
		cout<<store[val][k]<<endl;
	}
	return 0;
}