#include<bits/stdc++.h>
using namespace std;
const int N=2010,inf=2147483647;
int n,m,q,nn,x[N],y[N],ans[N],up[N][N<<2],dn[N][N<<2];char s[N][N];
void upu(int r,int x){up[r][x]=max(up[r][x<<1],up[r][x<<1|1]);}
void upd(int r,int x){dn[r][x]=min(dn[r][x<<1],dn[r][x<<1|1]);}
void updu(int r,int x,int v){x+=nn;up[r][x]=v;while(x>>=1)upu(r,x);}
void updd(int r,int x,int v){x+=nn;dn[r][x]=v;while(x>>=1)upd(r,x);}
int qryu(int r,int s,int t)
{
	int c=-inf;s+=nn-1;t+=nn+1;
	for(;s^t^1;s>>=1,t>>=1)
	{
		if(~s&1)c=max(c,up[r][s^1]);
		if(t&1)c=max(c,up[r][t^1]);
	}
	return c;
}
int qryd(int r,int s,int t)
{
	int c=inf;s+=nn-1;t+=nn+1;
	for(;s^t^1;s>>=1,t>>=1)
	{
		if(~s&1)c=min(c,dn[r][s^1]);
		if(t&1)c=min(c,dn[r][t^1]);
	}
	return c;
}
int calc(int x)
{
	int l=1,r=1,mxy,mny,res=0;
	for(;l<=m;l++)
	{
		if(l>r){r++;l--;continue;}
		mxy=qryu(x,l,r);mny=qryd(x,l,r);
		while(mxy!=inf&&mny!=-inf&&mny-mxy>=r-l&&r<m)
		{
			res=max(res,r-l+1);r++;
			mxy=max(mxy,up[x][r+nn]);
			mny=min(mny,dn[x][r+nn]);
		}
		if(r==m&&mxy!=inf&&mny!=-inf&&mny-mxy>=r-l){res=max(res,r-l+1);break;}
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);ans[q]=0;
	for(nn=1;nn<=m;nn<<=1);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=q;i++){scanf("%d%d",&x[i],&y[i]);s[x[i]][y[i]]='X';}
	for(int i=1;i<=m;i++)s[0][i]=s[n+1][i]='X';
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)up[i][j+nn]=s[i][j]=='X'?inf:(s[i-1][j]=='X'?i:up[i-1][j+nn]);
	for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)dn[i][j+nn]=s[i][j]=='X'?-inf:(s[i+1][j]=='X'?i:dn[i+1][j+nn]);
	for(int i=1;i<=n;i++)for(int j=nn-1;j;j--)upu(i,j),upd(i,j);
	for(int i=1;i<=n;i++)ans[q]=max(ans[q],calc(i));
	for(int i=q;i>1;i--)
	{
		s[x[i]][y[i]]='.';
		for(int j=x[i];j<=n;j++)if(s[j][y[i]]!='X')updu(j,y[i],s[j-1][y[i]]=='X'?j:up[j-1][y[i]+nn]);else break;
		for(int j=x[i];j;j--)if(s[j][y[i]]!='X')updd(j,y[i],s[j+1][y[i]]=='X'?j:dn[j+1][y[i]+nn]);else break;
		ans[i-1]=max(ans[i],calc(x[i]));
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}