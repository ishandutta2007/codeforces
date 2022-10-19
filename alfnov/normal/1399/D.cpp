#include<bits/stdc++.h>
using namespace std;
char s[200005];
int fa[200005],col[200005];
set<int>s1,s2;
int findfather(int x){return x==fa[x]?x:fa[x]=findfather(fa[x]);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		s1.clear();
		s2.clear();
		int n;
		cin>>n;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)fa[i]=i,col[i]=0;
		int c1=0,c2=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')s1.insert(i);
			else s2.insert(i);
		}
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='0')
			{
				if(!s2.size()||(*s2.begin())>i)continue;
				set<int>::iterator it=s2.lower_bound(i);
				it--;
				int cc=*it;
				fa[findfather(cc)]=findfather(i);
				s2.erase(cc);
			}else
			{
				if(!s1.size()||(*s1.begin())>i)continue;
				set<int>::iterator it=s1.lower_bound(i);
				it--;
				int cc=*it;
				fa[findfather(cc)]=findfather(i);
				s1.erase(cc);
			}
		}
		int cc=0;
		for(int i=1;i<=n;i++)
		{
			int tt=findfather(i);
			if(!col[tt])col[tt]=++cc;
		}
		cout<<cc<<endl;
		for(int i=1;i<n;i++)printf("%d ",col[fa[i]]);
		printf("%d\n",col[fa[n]]);
	}
	return 0;
}