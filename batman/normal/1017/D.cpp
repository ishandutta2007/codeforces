#include <bits/stdc++.h>
using namespace std;
#define M ((int)5010)
#define N ((int)12)
#define K ((int)110)

int n,m,q,ans[501*1000];
int w[N],cnt[M],cnt2[K];
vector <pair<int,int> > qu[M];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)cin>>w[i];
	for(int i=0;i<m;i++)
	{
		int x=0;
		string s;
		cin>>s;
		for(int j=0,num=1;j<s.size();j++,num*=2)
			x+=num*(s[j]=='1');
		cnt[x]++;
	}
	for(int i=0;i<q;i++)
	{
		int x=0,k;
		string s;
		cin>>s>>k;
		for(int j=0,num=1;j<s.size();j++,num*=2)
			x+=num*(s[j]=='1');
		qu[x].push_back({k,i});
	}
	for(int i=0;i<(1<<n);i++)
	{
		memset(cnt2,0,sizeof cnt2);
		for(int j=0;j<(1<<n);j++)
		{
			int score=0;
			for(int k=0;k<12;k++)
				if((i&(1<<k))==(j&(1<<k)))
					score+=w[k];
			if(score<=101)cnt2[score]+=cnt[j];
		}
		sort(qu[i].begin(),qu[i].end());
		int j=0,res=0;
		for(auto u:qu[i])
		{
			while(j<K && u.first>=j)res+=cnt2[j],j++;
			ans[u.second]=res;
		}
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
	return 0;
}