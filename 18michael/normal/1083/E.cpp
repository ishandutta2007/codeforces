#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,head=1,tail=0;LL ans=0;
int X[1000002],Y[1000002],id[1000002],st[1000002];
double dx[1000002];
LL a[1000002],dp[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return X[x]<X[y]? 1:0;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(X[i]),read(Y[i]),read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		while(head<tail && dx[head]>=Y[id[i]])++head;dp[id[i]]=1LL*X[id[i]]*Y[id[i]]-a[id[i]];
		if(i>1)dp[id[i]]+=max(-1LL*X[st[head]]*Y[id[i]]+dp[st[head]],0LL);ans=max(ans,dp[id[i]]);
		while(head<tail && -X[id[i]]*dx[tail-1]+dp[id[i]]>=-X[st[tail]]*dx[tail-1]+dp[st[tail]])--tail;
		st[++tail]=id[i];if(tail>head)dx[tail-1]=1.0*(dp[st[tail-1]]-dp[st[tail]])/(X[st[tail-1]]-X[st[tail]]);
	}
	return 0&printf("%lld",ans);
}