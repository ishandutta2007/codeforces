#include<cstdio>
#include<cstring>
const int N=10005;
int n,m;
int T[N*2];// 
int TT=0;
int main()
{
	bool tf=false;
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int k;
		scanf("%d",&k);
		TT++;
		bool lalal=false;
		while (k--)
		{
			int x;
			scanf("%d",&x);
			if (x>0)
			{
				if (T[x]==TT) lalal=true;
				T[x+n]=TT;
			}
			else
			{
				if (T[-x+n]==TT) lalal=true;
				T[-x]=TT;
			}
		}
		if (lalal==false) tf=true;
		if (tf) break;
	}
	if (!tf) printf("NO\n");
	else printf("YES\n");
	return 0;
}