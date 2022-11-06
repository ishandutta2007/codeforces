//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,taxi,m,x,a[100009],id[100009];
typedef pair<int,int>ss;
priority_queue <ss,vector<ss>,greater<ss> >q;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();m=read(),x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		puts("YES");
		while(!q.empty())q.pop();
		for(int i=1;i<=m;i++)q.push(ss{0,i});
		for(int i=1;i<=n;i++)
		{
			ss mmp=q.top();q.pop();
			id[i]=mmp.second;
		//	cout<<mmp.second<<" ";
			q.push(ss{mmp.first+a[i],id[i]});
		}
		for(int i=1;i<=n;i++)printf("%d ",id[i]);puts("");
	}
	return 0;
}