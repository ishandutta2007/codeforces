#include <iostream>
using namespace std;
long long cnt[1005],cnt2[1005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	cnt[i]=(n-i)/m+(n>=i);
	cnt[0]--;
	for (int i=0;i<m;i++)
	cnt2[(i*i)%m]+=cnt[i];
	long long ans=0;
	for (int i=0;i<m;i++)
	ans+=cnt2[i]*(cnt2[(m-i)%m]);
	printf("%I64d",ans);
}