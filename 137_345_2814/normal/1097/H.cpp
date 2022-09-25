#include<cstdio>
using namespace std;
#define N 30050
#define ll long long
int d,m,n,v[N],s[21];
ll l,r,pw[61],as[61][61];
int sl[16][61][N],sr[16][61][N],f[61][N],g[61][N];
ll solve(ll l,ll r,int rs,int di)
{
	if(r-l+1<n)return 0;
	if(l==0&&r==pw[di]-1)return as[di][rs];
	ll s1=0;
	if(pw[di-1]<n)
	{
		int nw=di-1;
		for(int k=l+1;k+n-1<=r+1;k++)
		{
			int fg=1,lb=k,rb=k+n-1,li=1;
			for(int j=0;j<d;j++)
			{
				if(lb<=pw[nw]&&rb>0)
				{
					int fl=lb,fr=rb,f1=0;if(fr>pw[nw])fr=pw[nw];
					if(fl==1)f1=sl[nw][(rs+s[j])%m][li]>=fr-fl+1;
					else f1=sr[nw][(rs+s[j])%m][fr-fl+1]>=fr-fl+1;
					li+=fr-fl+1;fg&=f1;
				}
				lb-=pw[nw],rb-=pw[nw];
				if(lb<1)lb=1;
			}
			s1+=fg;
		}
	}
	else
	{
		ll l1=l,r1=r;
		for(int j=0;j+1<d;j++)
		for(int l1=1;l1<n;l1++)if(pw[di-1]*(j+1)-l1>=l&&pw[di-1]*(j+1)+n-l1-1<=r)
		s1+=f[(rs+s[j]+s[d-1]*(di-1))%m][l1]&g[(rs+s[j+1])%m][n-l1];
		for(int j=0;j<d;j++)
		{
			if(l1<pw[di-1]&&r1>=0)
			{
				ll fl=l1,fr=r1;if(fr>=pw[di-1])fr=pw[di-1]-1;
				s1+=solve(fl,fr,(rs+s[j])%m,di-1);
			}
			l1-=pw[di-1];r1-=pw[di-1];
			if(l1<0)l1=0;if(r1<0)r1=-1;
		}
	}
	return s1;
}
int main()
{
	scanf("%d%d",&d,&m);
	for(int i=0;i<d;i++)scanf("%d",&s[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	int li=1,nw=0;
	for(int i=0;i<m;i++)for(int j=1;j<=n;j++)sl[0][i][j]=sr[0][i][j]=i<=v[j];
	while(1)
	{
		for(int i=0;i<m;i++)for(int j=1;j<=n;j++)
		{
			int le=j;
			for(int k=0;k<d;k++)
			{
				int r1=sl[nw][(i+s[k])%m][le];
				le+=r1;
				if(r1!=li)break;
			}
			sl[nw+1][i][j]=le-j;
		}
		for(int i=0;i<m;i++)for(int j=1;j<=n;j++)
		{
			int le=j;
			for(int k=d-1;k>=0;k--)
			{
				int r1=sr[nw][(i+s[k])%m][le];
				le-=r1;
				if(r1!=li)break;
			}
			sr[nw+1][i][j]=j-le;
		}
		nw++;li*=d;
		if(li>n)
		{
			for(int i=0;i<m;i++)for(int j=1;j<=n;j++)f[(i+nw*s[d-1])%m][j]=sr[nw][i][j]==j,g[i][j]=sl[nw][i][n-j+1]==j;
			break;
		}
	}
	pw[0]=1;nw=0;
	if(n==1)for(int i=0;i<m;i++)as[0][i]=i<=v[1];
	while(1)
	{
		if(1.0*pw[nw]*d>2e18)break;
		pw[nw+1]=pw[nw]*d;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<d;j++)as[nw+1][i]+=as[nw][(i+s[j])%m];
			if(pw[nw]<n)
			for(int k=1;k+n-1<=pw[nw+1];k++)
			{
				int fg=1,lb=k,rb=k+n-1,li=1;
				for(int j=0;j<d;j++)
				{
					if(lb<=pw[nw]&&rb>0)
					{
						int fl=lb,fr=rb,f1=0;if(fr>pw[nw])fr=pw[nw];
						if(fl==1)f1=sl[nw][(i+s[j])%m][li]>=fr-fl+1;
						else f1=sr[nw][(i+s[j])%m][fr-fl+1]>=fr-fl+1;
						li+=fr-fl+1;fg&=f1;
					}
					lb-=pw[nw],rb-=pw[nw];
					if(lb<1)lb=1;
				}
				as[nw+1][i]+=fg;
			}
			else
			{
				for(int j=0;j+1<d;j++)
				for(int l=1;l<n;l++)
				as[nw+1][i]+=f[(i+s[j]+s[d-1]*nw)%m][l]&g[(i+s[j+1])%m][n-l];
			}
		}
		nw++;
	}
	scanf("%lld%lld",&l,&r);l--;r--;
	printf("%lld\n",solve(l,r,0,nw+1));
}