#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n,las=1,tot=1;
LL ans=0;
int id[400002];
LL tim[400002]={};
char s[200002],ch[200002];
struct aaa
{
	int len,fa;
	int to[26];
}point[400002]={};
inline bool cmp(int a,int b)
{
	return point[a].len>point[b].len? 1:0;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline void add(int c,int val)
{
	int p=las,np=(++tot),q,nq;
	las=np,point[np].len=point[p].len+1,tim[np]=val;
	while(p && !point[p].to[c])point[p].to[c]=np,p=point[p].fa;
	if(!p)point[np].fa=1;
	else
	{
		q=point[p].to[c];
		if(point[q].len==point[p].len+1)point[np].fa=q;
		else
		{
			nq=(++tot),point[nq]=point[q],point[np].fa=point[q].fa=nq,point[nq].len=point[p].len+1;
			while(p && point[p].to[c]==q)point[p].to[c]=nq,p=point[p].fa;
		}
	}
}
int main()
{
	scanf("%d",&n),scanf("%s",s),scanf("%s",ch);
	for(int i=0;i<n;++i)add(s[i]-'a',(ch[i]=='0'));
	for(int i=2;i<=tot;++i)id[i]=i;
	sort(id+2,id+tot+1,cmp);
	for(int i=2;i<=tot;++i)tim[point[id[i]].fa]+=tim[id[i]],ans=max(ans,tim[id[i]]*point[id[i]].len);
	printf("%lld",ans);
	return 0;
}