#include<cstdio>
#include<cstdlib>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	srand(75345765);
	int n,lb=0,rb=1e9,ans=-1,t,ct;
	scanf("%d",&n);
	while(lb<=rb)
	{
		int mid=(lb+rb)>>1;
		printf("> %d\n",mid);ct++;
		fflush(stdout);
		scanf("%d",&t);
		if(t==1)ans=mid,lb=mid+1;
		else rb=mid-1;
	}
	ans++;
	int as=0;
	while(ct<=59)printf("? %d\n",1ll*rand()*rand()%n+1),fflush(stdout),ct++,scanf("%d",&t),as=gcd(ans-t,as);
	printf("! %d %d\n",ans-(n-1)*as,as);fflush(stdout);
}