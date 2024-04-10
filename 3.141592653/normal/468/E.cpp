#include<bits/stdc++.h>
const int mod=1e9+7;
class field
{
	int n,k;
	std::map<int,int>M[1111];
	int rank[111][111],label[111][111],cnt[111][111],ref[111][111],maxx[111],maxy;
	int fac[1111111];
	struct node{int x,y,w;}p[111];
	bool arrangeLabel()
	{
		register int i,ii;
		for(i=1;i<=maxy;i++)
			for(ii=1;ii<=k;ii++)cnt[i][ii]=ref[i][ii]=0;
		for(i=1;i<=k;i++)cnt[p[i].y][p[i].x]++,ref[p[i].y][p[i].x]=i;
		for(i=1;i<=maxy;i++)
			for(ii=1;ii<=k;ii++)cnt[i][ii]+=cnt[i-1][ii];
		for(i=1;i<=maxy;i++)
		{
			maxx[i]=0;
			for(ii=1;ii<=k;ii++)
			{
				if(cnt[i][ii]&&cnt[i][ii]!=cnt[maxy][ii])
					label[i][ii]=maxx[i],rank[i][maxx[i]++]=ii;
				else label[i][ii]=-1;
			}
		}
		for(i=1;i<=maxy;i++)if(maxx[i]>18)return 0;
		return 1;
	}
	void relabel()
	{
		std::random_shuffle(p+1,p+k+1);
		std::map<int,int>Mx,My;
		register int i,cx=0,cy=0;
		for(i=1;i<=k;i++)
		{
			int lx=Mx[p[i].x];
			if(lx)p[i].x=lx;
			else Mx[p[i].x]=++cx,p[i].x=cx;
			int ly=My[p[i].y];
			if(ly)p[i].y=ly;
			else My[p[i].y]=++cy,p[i].y=cy;
		}
		maxy=cy;
	}
	void swapxy()
	{for(register int i=1;i<=k;i++)std::swap(p[i].x,p[i].y);}
	int dp[2][1<<18|15][55];
	bool ban[111];
	void adp(int&x,int y){(x+=y)<mod?0:x-=mod;}
	void dodp()
	{
		register int i,ii,c,S,T,t=0;
		dp[0][0][0]=1;
		for(i=1;i<=maxy;i++)
		{
			t=!t;
			for(S=0;S<=(1<<maxx[i])-1;S++)for(ii=0;ii<=k;ii++)dp[t][S][ii]=0;
			for(ii=0;ii<=k;ii++)ban[i]=0;
			for(S=0;S<=(1<<maxx[i-1])-1;S++)
			{
				int S0=S;
				for(ii=0;ii<=maxx[i-1];ii++)ban[rank[i-1][ii]]=S0&1,S0>>=1;
				for(ii=1,T=0;ii<=k;ii++)if(~label[i][ii])
					if(ban[ii])T|=(1<<label[i][ii]);
				for(c=0;c<i;c++)adp(dp[t][T][c],dp[!t][S][c]);
				for(ii=1;ii<=k;ii++)
					if(ref[i][ii]&&!ban[ii])
					{
						if(label[i][ii]<0)
						{
							for(c=0;c<i;c++)
								dp[t][T][c+1]=
								(dp[t][T][c+1]+dp[!t][S][c]*1ll*p[ref[i][ii]].w)%mod;
						}
						else
						{
							int U=T|(1<<label[i][ii]);
							for(c=0;c<i;c++)
								dp[t][U][c+1]=
								(dp[t][U][c+1]+dp[!t][S][c]*1ll*p[ref[i][ii]].w)%mod;
						}
					}
			}
		}
		int ans=0;
		for(c=0;c<=maxy;c++)ans=(ans+dp[maxy&1][0][c]*1ll*fac[n-c])%mod;
		printf("%d\n",ans);
	}
public:
	void solve()
	{
		scanf("%d%d",&n,&k);
		register int i;
		for(i=fac[0]=1;i<=n;i++)fac[i]=fac[i-1]*1ll*i%mod;
		for(i=1;i<=k;i++)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w),
			p[i].w=(p[i].w+mod-1)%mod;
		relabel();
		if(!arrangeLabel())swapxy(),relabel(),arrangeLabel();
		dodp();
	}
}Solver;
int main()
{
	srand(time(0));
	Solver.solve();
}
/*
This end-of-file is just the beginning.
*/