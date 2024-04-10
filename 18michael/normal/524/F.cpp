#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m=1,t=0,st_t=0;
int pre[2000002],cnt[2000002],sa[2000002],id[2000002],px[2000002],rk[2000002],oldrk[2000002];
char s[2000002];
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > pq;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y,int w)
{
	return oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w];
}
inline int abs(int x)
{
	return x>0? x:-x;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1),rk[0]=2*n+1;
	for(int i=1;i<=n;++i)s[n+i]=s[i];n<<=1;
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+(s[i]=='('? 1:-1);
	for(int i=1;i<=n;++i)++cnt[rk[i]=(s[i]==')')];
	for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)sa[cnt[rk[i]]--]=i;
	for(int l=1,p=0;l<n && p<n;l<<=1,m=p)
	{
		p=0;
		for(int i=n;i>n-l;--i)id[++p]=i;
		for(int i=1;i<=n;++i)if(sa[i]>l)id[++p]=sa[i]-l;
		for(int i=0;i<=m;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)++cnt[px[i]=rk[id[i]]];
		for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
		for(int i=n;i;--i)sa[cnt[px[i]]--]=id[i];
		for(int i=1;i<=n;++i)oldrk[i]=rk[i];
		p=0;
		for(int i=1;i<=n;++i)rk[sa[i]]=cmp(sa[i],sa[i-1],l)? p:(++p);
	}
	n>>=1;
	for(int i=1;i<=n;++i)pq.push(P(pre[i],i));
	for(int i=1;i<=n;++i)
	{
		while(pq.top().second<i)pq.pop();
		if(pq.top().first-pre[i-1]+(pre[n]<=0? -pre[n]:0)>=0 && rk[i]<rk[t])t=i;
		pq.push(P(pre[n+i],n+i));
	}
	for(int i=1;i<=-pre[n];++i)printf("(");
	for(int i=0;i<n;++i)printf("%c",s[((t+i-1)%n)+1]);
	for(int i=1;i<=pre[n];++i)printf(")");
	return 0;
}