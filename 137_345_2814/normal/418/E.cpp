#include<cstdio>
#include<map>
using namespace std;
#define N 100500
#define M 301
int n,q,a,b,c,v[N],s1[N],su[M][N*2],ct[M][N],t=400,ct1;
map<int,int> st;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),s1[i]=st[v[i]]?st[v[i]]:(st[v[i]]=++ct1);
	scanf("%d",&q);
	for(int i=1;i<=n/t;i++)
	{
		for(int j=1;j<=n;j++)su[i][j]=su[i-1][j],ct[i][j]=ct[i-1][j];
		for(int j=(i-1)*t+1;j<=i*t;j++)ct[i][++su[i][s1[j]]]++;
	}
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==2)
		{
			if(b==1)printf("%d\n",v[c]);
			else
			{
				int tp=c/t;
				for(int j=tp*t+1;j<=c;j++)ct[tp][++su[tp][s1[j]]]++;
				if(b&1)printf("%d\n",ct[tp][su[tp][s1[c]]]);
				else printf("%d\n",su[tp][s1[c]]);
				for(int j=tp*t+1;j<=c;j++)ct[tp][su[tp][s1[j]]--]--;
			}
		}
		else
		{
			b^=c^=b^=c;v[b]=c;
			if(!st[c])st[c]=++ct1;c=st[c];
			int tp=(b-1)/t;
			for(int i=tp+1;i<=n/t;i++)ct[i][su[i][s1[b]]--]--;
			s1[b]=c;
			for(int i=tp+1;i<=n/t;i++)ct[i][++su[i][s1[b]]]++;
		}
	}
}