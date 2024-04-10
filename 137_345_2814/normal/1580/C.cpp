#include<cstdio>
using namespace std;
#define N 200500
#define M 505
int n,m,s[N][2],vl[N],as,a,b,ti[N];
int tp[M][M];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&s[i][0],&s[i][1]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);as+=vl[i];
		if(a==1)
		{
			ti[b]=i;
			if(s[b][0]+s[b][1]>=450)
			{
				int nw=i+s[b][0];
				while(nw<=m)
				{
					vl[nw]++;
					nw+=s[b][1];
					if(nw<=m)vl[nw]--;
					nw+=s[b][0];
				}
			}
			else
			{
				int nw=i+s[b][0];
				for(int i=0,v=nw%(s[b][0]+s[b][1]);i<s[b][1];i++,v=(v==s[b][0]+s[b][1]-1?0:v+1))tp[s[b][0]+s[b][1]][v]++;
			}
		}
		else
		{
			if(s[b][0]+s[b][1]>=450)
			{
				int nw=ti[b]+s[b][0];
				while(nw<=m)
				{
					if(nw<=i&&nw+s[b][1]>i)as--;
					vl[nw]--;
					nw+=s[b][1];
					if(nw<=m)vl[nw]++;
					nw+=s[b][0];
				}
			}
			else
			{
				int nw=ti[b]+s[b][0];
				for(int i=0,v=nw%(s[b][0]+s[b][1]);i<s[b][1];i++,v=(v==s[b][0]+s[b][1]-1?0:v+1))tp[s[b][0]+s[b][1]][v]--;
			}
		}
		int ras=as;
		for(int j=1;j<=500;j++)ras+=tp[j][i%j];
		printf("%d\n",ras);
	}
}