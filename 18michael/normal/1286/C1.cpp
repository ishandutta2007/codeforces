#include<bits/stdc++.h>
using namespace std;
int n,mid,t=0;
string s;
char ans[102];
int cnt[102][26];
map<string,int> mp[3];
map<string,int>::iterator it;
inline void query(int l,int r)
{
	if(l<=r)printf("? %d %d\n",l,r),fflush(stdout);
	for(int i=l,x;i<=r;++i)
		for(int j=i;j<=r;++j)
		{
			cin>>s,x=s.length(),memset(cnt[0],0,sizeof(cnt[0]));
			for(int i=0;i<x;++i)++cnt[0][s[i]-'a'];
			for(int i=1;i<26;++i)cnt[0][i]+=cnt[0][i-1];
			for(int i=0;i<26;++i)for(int j=(i? cnt[0][i-1]:0);j<cnt[0][i];++j)s[j]='a'+i;
			++mp[t][s];
		}
	++t;
}
int main()
{
	for(scanf("%d",&n),mid=n/2+1,query(1,n),query(mid+1,n),query(mid,n),memset(cnt[0],0,sizeof(cnt[0])),it=mp[2].begin();it!=mp[2].end();++it)
		if(mp[1][(*it).first]<(*it).second)
		{
			t=((*it).first).length();
			for(int i=0;i<t;++i)++cnt[t][(*it).first[i]-'a'];
		}
	for(int i=mid;i<=n;++i)
		for(int j=0;j<26;++j)
			if(cnt[i-mid+1][j]>cnt[i-mid][j])
			{
				ans[i]='a'+j;
				break;
			}
	for(memset(cnt,0,sizeof(cnt)),it=mp[0].begin();it!=mp[0].end();++it)
	{
		t=((*it).first).length();
		for(int i=0;i<t;++i)cnt[n-t+1][(*it).first[i]-'a']+=(*it).second;
	}
	for(int i=(n+1)/2;i>1;--i)for(int j=0;j<26;++j)cnt[i][j]-=cnt[i-1][j];
	for(int i=1;i<(n+1)/2;++i)for(int j=0;j<26;++j)cnt[i][j]-=cnt[i+1][j];
	for(int i=1;i<mid;++i)
	{
		--cnt[i][ans[n-i+1]-'a'];
		for(int j=0;j<26;++j)
			if(cnt[i][j])
			{
				ans[i]='a'+j;
				break;
			}
	}
	return 0&printf("! %s",ans+1);
}