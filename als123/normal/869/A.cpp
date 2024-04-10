#include<cstdio>
#include<cstring>
const int N=2005;
int n;
int a[N],b[N];
bool in[2000005];
int main()
{
	memset(in,false,sizeof(in));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		in[a[u]]=true;
	}
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&b[u]);
		in[b[u]]=true;
	}
	int tot=0;
	for (int u=1;u<=n;u++)	
		for (int i=1;i<=n;i++)
		{
			if ((a[u]^b[i])<=2000000)
				tot=tot+in[a[u]^b[i]];
		}
	if (tot%2==0) printf("Karen\n");
	else printf("Koyomi\n");
	return 0;
}