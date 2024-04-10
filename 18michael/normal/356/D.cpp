#include<bits/stdc++.h>
using namespace std;
int n,S,sq;
int l[80002],id[80002],block[80002],s[292],e[292],from[80002]={};
bitset<100002> bs[292],bs1[292];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return l[x]<l[y]? 1:0;
}
int main()
{
	read(n),read(S),sq=sqrt(n);
	for(int i=1;i<=n;++i)read(l[i]),id[i]=i;
	sort(id+1,id+n+1,cmp),bs[0][0]=1;
	if((S-=l[id[n]])<0)return 0&puts("-1");
	for(int i=1;i<=n;++i)block[i]=(i-1)/sq+1;
	for(int i=1;i<=block[n];++i)
	{
		s[i]=(i-1)*sq+1,e[i]=min(i*sq,n-1),bs[i]=bs[i-1];
		for(int j=s[i];j<=e[i];++j)bs[i]|=(bs[i]<<l[id[j]]);
	}
	if(!bs[block[n]][S])return 0&puts("-1");
	for(int i=block[n];i;--i)
	{
		bs1[0]=bs[i-1];
		for(int j=s[i];j<=e[i];++j)bs1[j-s[i]+1]=(bs1[j-s[i]]|(bs1[j-s[i]]<<l[id[j]]));
		for(int j=e[i];j>=s[i];--j)if(S>=l[id[j]] && bs1[j-s[i]][S-l[id[j]]])S-=l[id[j]];else from[id[j+1]]=id[j];
	}
	for(int i=1;i<=n;++i)if(from[i])printf("%d 1 %d\n",l[i]-l[from[i]],from[i]);else printf("%d 0\n",l[i]);
	return 0;
}