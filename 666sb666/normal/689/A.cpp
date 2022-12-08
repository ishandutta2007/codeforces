#include<cstdio>
#include<cstring>
int n;
bool a[10];
int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int x;
		char ch=getchar();
		while(ch<'0'||ch>'9')ch=getchar();
		x=ch-'0';
		a[x]=true;
	}
	bool flag=false;
	if(a[0]&&a[1]||a[0]&&a[2]||a[0]&&a[3])flag=true;
	if(a[1]&&a[9]||a[3]&&a[7])flag=true;
	if(a[1]&&a[6]&&a[7]||a[3]&&a[4]&&a[9])flag=true;
	if(a[7]&&a[9]&&a[2])flag=true;
	if(a[2]&&a[4]&&a[9]||a[2]&&a[6]&&a[7])flag=true;
	if(flag)printf("YES\n");
	else printf("NO\n");
	return 0;
}