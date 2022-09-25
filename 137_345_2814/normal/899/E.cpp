#include<cstdio>
#include<set>
using namespace std;
#define N 200050
int pr[N],nt[N],cl[N],n,ct,sz[N],cnt,sum,c[N];
struct sth{int a,b,c;friend bool operator <(sth a,sth b){return a.a==b.a?(a.c==b.c?a.b<b.b:a.c>b.c):a.a<b.a;}};
multiset<sth> tp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)
	{
		if(i<=n)scanf("%d",&cl[i]);
		if(i==1||cl[i]==cl[i-1])sum++;
		else cnt++,sz[cnt]=sum,nt[cnt-1]=cnt,pr[cnt]=cnt-1,c[cnt]=cl[i-1],tp.insert((sth){sum,cl[i-1],cnt}),sum=1;
	}
	while(!tp.empty())
	{
		sth a=*(tp.rbegin());ct++;tp.erase(a);
		nt[pr[a.c]]=nt[a.c];
		pr[nt[a.c]]=pr[a.c];
		if(c[pr[a.c]]==c[nt[a.c]]&&pr[a.c]&&nt[a.c])
		{
			tp.erase((sth){sz[pr[a.c]],c[pr[a.c]],pr[a.c]});
			tp.erase((sth){sz[nt[a.c]],c[nt[a.c]],nt[a.c]});
			nt[pr[pr[a.c]]]=nt[pr[a.c]];
			pr[nt[pr[a.c]]]=pr[pr[a.c]];
			sz[nt[a.c]]+=sz[pr[a.c]];
			tp.insert((sth){sz[nt[a.c]],c[nt[a.c]],nt[a.c]});
		}
	}
	printf("%d\n",ct);
}