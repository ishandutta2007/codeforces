#include<cstdio>
#include<algorithm>
using namespace std;
#define N 2333333
struct sth{int a,b;friend bool operator <(sth a,sth b){return a.a<b.a;}}v[N];
int n,s[N],as;
long long k;
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=1;i<n;i++)v[i]=(sth){i,s[i+1]-s[i]};
	for(int i=1;i<n;i++)v[n-1+i]=(sth){i,s[n-i+1]-s[n-i]};
	sort(v+1,v+n*2-1);
	as=s[n]-s[1];
	for(int i=1;i<=n*2-2;i++)
	{
		if(k<=1ll*v[i].a*v[i].b)
		{
			as-=k/v[i].a;
			if(as<0)as=0;
			printf("%d\n",as);
			return 0;
		}
		else k-=1ll*v[i].a*v[i].b,as-=v[i].b;
	}
	if(as<0)as=0;
	printf("%d\n",as);
}