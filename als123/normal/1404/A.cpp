#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
char ss[N];
char t[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		scanf("%s",ss+1);
		for (int u=0;u<=n;u++)	t[u]=0;
		for (int u=1;u<=n;u++) if (ss[u]!='?')	t[u%k]=ss[u];
		bool flag=true;
		for (int u=1;u<=n;u++) if (t[u%k]!=-1)
		{
			if (ss[u]=='?')	ss[u]=t[u%k];
			if (ss[u]!=t[u%k]) flag=false;
		}
		if (!flag) {printf("NO\n");continue;}
		int A=0,B=0;
		for (int u=1;u<=k;u++)
		{
			if (ss[u]=='0') A++;
			if (ss[u]=='1') B++;
		}
	//	printf("%d %d\n",A,B);
		if (A>k/2||B>k/2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}