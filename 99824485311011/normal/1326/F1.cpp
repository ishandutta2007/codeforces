#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int Sl[1<<14][1<<6][14],Sr[1<<14][1<<6][14],n;
bool flag[20][20];
void dfs1(int np,int cS,int cseq,int lst)
{
	if(np==n/2)
	{
		Sl[cS][cseq][lst]++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!((cS>>i)&1))
		{
			dfs1(np+1,cS|(1<<i),lst==-1?cseq:cseq|(flag[lst][i]<<(np-1)),i);
		}
	}
}
void dfs2(int np,int cS,int cseq,int lst,int st)
{
	if(np==n)
	{
		Sr[cS][cseq][st]++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!((cS>>i)&1))
		{
			dfs2(np+1,cS|(1<<i),lst==-1?cseq:cseq|(flag[lst][i]<<(np-(n/2)-1)),i,st==-1?i:st);
		}
	}
}
long long ans[1<<14],tS[1<<6][2];
char s[20];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<n;j++)
		{
			if(s[j]=='1')flag[i][j]=1;
			else flag[i][j]=0;
		}
	}
	dfs1(0,0,0,-1);
	dfs2(n/2,0,0,-1,-1);
	for(int S1=0;S1<(1<<n);S1++)
	{
		if(__builtin_popcount(S1)==n/2)
		{
			int S2=((1<<n)-1)^S1;
			for(int i=0;i<n;i++)
			{
				if((S1>>i)&1)
				{
					for(int j=0;j<n;j++)
					{
						if((S2>>j)&1)
						{
							for(int R=0;R<(1<<(n-(n/2)-1));R++)
							{
								tS[R][flag[i][j]]+=Sr[S2][R][j];
							}
//							int mid=(int)(flag[i][j])<<(n/2-1);
//							for(int L=0;L<(1<<((n/2)-1));L++)
//							{
//								for(int R=0;R<(1<<(n-(n/2)-1));R++)
//								{
//									ans[L|mid|(R<<(n/2))]+=(ll)Sl[S1][L][i]*Sr[S2][R][j];
//								}
//							}
						}
					}
					for(int f=0;f<2;f++)
					{
						int mid=f<<(n/2-1);
						for(int L=0;L<(1<<((n/2)-1));L++)
						{
							for(int R=0;R<(1<<(n-(n/2)-1));R++)
							{
								ans[L|mid|(R<<(n/2))]+=(ll)Sl[S1][L][i]*tS[R][f];
							}
						}
					}
					memset(tS,0,sizeof(tS));
				}
			}
		}
	}
	for(int i=0;i<(1<<(n-1));i++)printf("%lld ",ans[i]);
	return 0;
}