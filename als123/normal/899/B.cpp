#include<cstdio>
const int N=30;
int a[N];
int n;
int b[1000],tot=0;
int c[]={0,31,0,31,30,31,30,31,31,30,31,30,31};
void bt (int x)
{
	for (int u=1;u<=12;u++)
	{
		if (u==2)
		{
			if (x==1) b[++tot]=28;
			else b[++tot]=29;
		}
		else b[++tot]=c[u];
	}
}
bool check()
{
	for (int u=1;u<=tot;u++)
	{
		bool tf=true;
		for (int i=1;i<=n;i++)
			if (a[i]!=b[u+i-1])
			{
				tf=false;
				break;
			}
		if (tf) return true;
	}
	return false;
}
int main()
{
	bt(1);bt(1);bt(0);bt(1);bt(1);
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	if (check()) printf("YES\n");
	else printf("NO");
	return 0;
}