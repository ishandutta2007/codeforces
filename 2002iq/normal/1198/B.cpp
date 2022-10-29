#include <iostream>
using namespace std;
int arr[200005],pos[200005],pay[200005];
int main()
{
	int n,q;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	scanf("%d",&q);
	for (int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int p,x;
			scanf("%d%d",&p,&x);
			arr[p]=x;
			pos[p]=i;
		}
		else
		{
			int x;
			scanf("%d",&x);
			pay[i]=x;
		}
	}
	for (int i=q-1;i>=0;i--)
	pay[i]=max(pay[i],pay[i+1]);
	for (int i=1;i<=n;i++)
	printf("%d ",max(pay[pos[i]],arr[i]));
}