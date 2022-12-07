#include<cstdio>
#include<cstring>
const int N=100005;
int n,k;
int a[N];
int L[N],R[N];// 
int mymax (int x,int y){return x>y?x:y;}
int mymin (int x,int y){return x<y?x:y;}
void solve2 ()
{
	L[1]=a[1];
	for (int u=2;u<=n;u++)
		L[u]=mymin(L[u-1],a[u]);
	R[n]=a[n];
	for (int u=n-1;u>=1;u--)
		R[u]=mymin(R[u+1],a[u]);
	/*for (int u=1;u<=n;u++) printf("%d ",L[u]);
	for (int u=1;u<=n;u++) printf("%d ",R[u]);*/
	int lalal=mymax(L[1],R[2]);
	for (int u=2;u<n;u++)
		lalal=mymax(lalal,mymax(L[u],R[u+1]));
	printf("%d\n",lalal);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++)
		scanf("%d",&a[u]);
	if (k==1)
	{
		int lalal=a[1];
		for (int u=2;u<=n;u++)	lalal=mymin(lalal,a[u]);
		printf("%d\n",lalal);
		return 0;
	}
	else	if (k==2) solve2();
	else
	{
		int lalal=a[1];
		for (int u=2;u<=n;u++)	lalal=mymax(lalal,a[u]);
		printf("%d\n",lalal);
		return 0;
	}
	return 0;
}