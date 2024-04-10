#include<cstdio>
using namespace std;
#define N 200500
#define ll long long
int n,p[N],s[N][2],a,b,ls[N],rs[N];
ll as;
struct BIT{
	int tr[N];
	void add(int x){for(int i=x;i<=n*2;i+=i&-i)tr[i]++;}
	int que(int x){int as=0;for(int i=x;i;i-=i&-i)as+=tr[i];return as;}
}tr;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		p[b]=a;p[a]=b;
	}
	for(int i=1;i<=n*2;i++)
	{
		if(p[i]<i)s[p[i]][0]+=tr.que(i)-tr.que(p[i]),s[p[i]][0]/=2;
		else s[i][0]-=tr.que(p[i])-tr.que(i),s[i][1]=tr.que(n*2)-tr.que(p[i]),ls[p[i]]++,rs[i]++;
		tr.add(p[i]);
	}
	for(int i=1;i<=n*2;i++)ls[i]+=ls[i-1];
	for(int i=n*2;i>=1;i--)rs[i]+=rs[i+1];
	for(int i=1;i<=n*2;i++)if(p[i]>i)s[i][1]+=ls[i-1]+rs[p[i]+1];
	for(int i=1;i<=n*2;i++)if(p[i]>i)as-=1ll*s[i][0]*s[i][1]*2,s[i][0]+=s[i][1];
	for(int i=1;i<=n*2;i++)if(p[i]>i)as+=1ll*s[i][0]*(s[i][0]-1)/2+1ll*(n-2-s[i][0])*(n-1-s[i][0])/2;
	as-=1ll*n*(n-1)*(n-2)/6;as/=2;
	printf("%lld\n",as);
}