#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 105000
int n,m,k,v[N],mx[N],r1,r2,fr[N],a,b,c,sp[N];
struct sth{int i,j;}t1[N];
vector<sth> s[N];
struct sth2{int i;long double s;}t2[N];
bool cmp(sth a,sth b){return a.j>b.j;}
bool cmp2(sth2 a,sth2 b){return a.s>b.s;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),mx[i]=v[i];
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);sp[i]=a;
		if(a==1){if(mx[b]<c)mx[b]=c,fr[b]=i;}
		if(a==2)s[b].push_back((sth){i,c});
		if(a==3)t1[++r1]=(sth){i,c};
	}
	for(int i=1;i<=n;i++)if(v[i]<mx[i])s[i].push_back((sth){fr[i],mx[i]-v[i]});
	for(int i=1;i<=n;i++)
	{
		sort(s[i].begin(),s[i].end(),cmp);
		int sz=s[i].size();
		long long s1=v[i];
		for(int j=0;j<sz;j++)
		t2[++r2]=(sth2){s[i][j].i,1.0*(s1+s[i][j].j)/s1},s1+=s[i][j].j;
	}
	sort(t1+1,t1+r1+1,cmp);
	sort(t2+1,t2+r2+1,cmp2);
	if(k>r1+r2)k=r1+r2;
	printf("%d\n",k);
	int l1=1,l2=1;
	for(int i=1;i<=k;i++)
	{
		if(t1[l1].j>t2[l2].s&&l1<=r1)l1++;
		else {
		if(sp[t2[l2].i]==1)printf("%d ",t2[l2].i);l2++;
		}
	}
	l1=1,l2=1;
	for(int i=1;i<=k;i++)
	{
		if(t1[l1].j>t2[l2].s&&l1<=r1)l1++;
		else {
		if(sp[t2[l2].i]==2)printf("%d ",t2[l2].i);l2++;
		}
	}
	for(int i=1;i<l1;i++)printf("%d ",t1[i].i);
}