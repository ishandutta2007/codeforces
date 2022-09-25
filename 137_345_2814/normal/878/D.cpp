#include<cstdio>
#include<bitset>
#define N 100050
using namespace std;
bitset<4100> s[N];
int n,k,q,e[13][N],ct,a,b,c;
int main()
{
	scanf("%d%d%d",&n,&k,&q);ct=k;
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&e[i][j]);
	for(int i=0;i<1<<k;i++)
	for(int j=1;j<=k;j++)
	if(i&(1<<j-1))
	s[j][i]=1;
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)s[++ct]=s[b]|s[c];
		else if(a==2)s[++ct]=s[b]&s[c];
		else
		{
			int ans=0;
			for(int i=1;i<=k;i++)
			if(e[i][c]>ans)
			{
				int tmp=0;
				for(int j=1;j<=k;j++)
				if(e[j][c]>=e[i][c])tmp+=1<<(j-1);
				if(s[b][tmp])ans=e[i][c];
			}
			printf("%d\n",ans);
		}
	}
}