#include<cstdio>
#include<cstring>
const int M=105;
int X[M],Y[M];
int n,m;
int get (int x,int y)
{
	if (x%y==0) return x/y;
	else return x/y+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)	scanf("%d%d",&X[u],&Y[u]);
	int XX=-1;
	for (int u=1;u<=105;u++)// 
	{
		bool tf=false;
		for (int i=1;i<=m;i++)
		{
			if (get(X[i],u)!=Y[i])
			{
				tf=true;
				break;
			}
		}
		if (tf==false)//
		{
			if (XX!=-1&&get(n,u)!=get(n,XX)) {printf("-1");return 0;}
			XX=u;
		}
	}
	if (XX==-1) printf("-1\n");
	else printf("%d",get(n,XX));
	return 0;
}