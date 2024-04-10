#include<cstdio>
using namespace std;
#define N 1000600
int T,n,c,a,su[N],is[N];
void solve()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=c;i++)su[i]=is[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a),is[a]=1,su[a]++;
	for(int i=1;i<=c;i++)su[i]+=su[i-1];
	for(int i=1;i<=c;i++)if(!is[i])
	for(int j=1;i*j<=c;j++)if(is[j])
	{
		int lb=i*j,rb=(i+1)*j-1;
		if(rb>c)rb=c;
		if(su[rb]>su[lb-1]){printf("No\n");return;}
	}
	printf("Yes\n");
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
}