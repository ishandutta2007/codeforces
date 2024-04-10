#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
int n,las=1,tot=1;
LL ans=0;
char s[100008];
int id[200008];
LL tim[200008];
struct aaa
{
	int fa,len;
	int to[26];
}a[200008];
inline bool cmp(int x,int y)
{
	return a[x].len>a[y].len? 1:0;
}
inline void add(int c)
{
	int p=las,np=(++tot),q,nq;
	las=np,a[np].len=a[p].len+1,tim[np]=1;
	while(p && !a[p].to[c])a[p].to[c]=np,p=a[p].fa;
	if(!p)a[np].fa=1;
	else
	{
		q=a[p].to[c];
		if(a[q].len==a[p].len+1)a[np].fa=q;
		else
		{
			nq=(++tot),a[nq]=a[q],a[nq].len=a[p].len+1,a[np].fa=a[q].fa=nq;
			while(p && a[p].to[c]==q)a[p].to[c]=nq,p=a[p].fa;
		}
	}
}
int main()
{
	scanf("%s",s),n=strlen(s);
	for(int i=0;i<n;++i)add(s[i]-'a');
	for(int i=2;i<=tot;++i)id[i]=i;
	sort(id+2,id+tot+1,cmp);
	for(int i=2;i<=tot;++i)tim[a[id[i]].fa]+=tim[id[i]];
	for(int i=2;i<=tot;++i)ans+=(tim[i]+1)*tim[i]/2*(a[i].len-a[a[i].fa].len);
	printf("%lld",ans);
	return 0;
}