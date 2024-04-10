#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
#define N 333000
#define M 2220000
#define mod 998244353
stack<int> st;
int head[N],cnt,ins[N],is[N],c[N],id[N],le,vis[N],ntt[N],s1[N],s2[N],s3[N],s4[N],s5[N],sth[M*5],lb[N],len[N],rev[N],n,m,a,b,ds[N],mx1,vl,as,sz[N],mx2,ct2;
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
int pw(int a,int p){int ans=1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
void dft(int s,int *a,int t)
{
    for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)+(i&1)*s/2;
    for(int i=0;i<s;i++)ntt[rev[i]]=a[i];
    for(int l=2;l<=s;l<<=1)
    {
        int s1=pw(3,(mod-1)/l);
        if(t==-1)s1=pw(s1,mod-2);
        for(int j=0;j<s;j+=l)
        for(int k=j,st=1;k<j+(l>>1);k++,st=1ll*st*s1%mod)
        {
            int a1=ntt[k],a2=1ll*ntt[k+(l>>1)]*st%mod;
            ntt[k]=a1+a2-(a1+a2>=mod?mod:0);
            ntt[k+(l>>1)]=a1-a2+(a1<a2?mod:0);
        }
    }
    int inv=pw(s,t==-1?mod-2:0);
    for(int i=0;i<s;i++)a[i]=1ll*ntt[i]*inv%mod;
}
void dfs0(int u,int fa)
{
	ins[u]=1;st.push(u);
	for(int i=head[u];i&&!le;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		if(ins[ed[i].t])
		{
			while(1)
			{
				int a=st.top();st.pop();
				c[++le]=a;
				if(a==ed[i].t)break;
			}
		}
		else
		dfs0(ed[i].t,u);
	}
	if(!st.empty()&&st.top()==u)st.pop();
}
void dfs1(int u,int fa)
{
	sz[u]=1;
	int mx=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dfs1(ed[i].t,u),mx=max(mx,sz[ed[i].t]),sz[u]+=sz[ed[i].t];
	mx=max(mx,vl-sz[u]);
	if(mx<mx1)mx1=mx,as=u;
}
void dfs2(int u,int fa)
{
	ds[u]=ds[fa]+1;
	s2[ds[u]]++;
	if(mx2<ds[u])mx2=ds[u];
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dfs2(ed[i].t,u);
}
void work(int u)
{
	int mx=0;ds[u]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	{
		mx2=0;
		dfs2(ed[i].t,u);
		for(int i=1;i<=mx2;i++)s1[i]+=s2[i],s3[i]=s2[i],s2[i]=0;
		int l=1;while(l<=mx2*2)l<<=1;
		for(int i=mx2+1;i<l;i++)s3[i]=0;
		dft(l,s3,1);for(int i=0;i<l;i++)s3[i]=1ll*s3[i]*s3[i]%mod;dft(l,s3,-1);
		for(int i=0;i<l;i++)s4[i]=(s4[i]-s3[i]+mod)%mod;
		if(mx<mx2)mx=mx2;
	}
	int l=1;while(l<=mx*2)l<<=1;
	for(int i=mx+1;i<l;i++)s1[i]=0;
	dft(l,s1,1);for(int i=0;i<l;i++)s1[i]=1ll*s1[i]*(s1[i]+2)%mod;dft(l,s1,-1);
	for(int i=0;i<l;i++)s4[i]=(s4[i]+s1[i])%mod,s1[i]=0;
	return;
}
void dfs3(int u)
{
	vis[u]=1;work(u);
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	{
		vl=sz[ed[i].t],mx1=1e9;
		dfs1(ed[i].t,u);
		dfs3(as);
	}
}
void fz1(int l,int r)
{
	if(l>=r)return;
	int mid=(l+r)>>1;
	int m1=0,m2=0;
	for(int i=l;i<=mid;i++)m1=max(len[i]+mid-i,m1);
	for(int i=mid+1;i<=r;i++)m2=max(len[i]+i-mid-1,m2);
	for(int i=0;i<=m1;i++)s1[i]=0;
	for(int i=0;i<=m2;i++)s2[i]=0;
	for(int i=l;i<=mid;i++)
	for(int j=0;j<=len[i];j++)s1[mid-i+j]+=sth[j+lb[i]];
	for(int i=mid+1;i<=r;i++)
	for(int j=0;j<=len[i];j++)s2[i-mid-1+j]+=sth[j+lb[i]];
	int s=1;while(s<=m1+m2)s<<=1;
	for(int i=m1+1;i<s;i++)s1[i]=0;
	for(int i=m2+1;i<s;i++)s2[i]=0;
	dft(s,s1,1);dft(s,s2,1);for(int i=0;i<s;i++)s1[i]=2ll*s1[i]*s2[i]%mod;dft(s,s1,-1);
	for(int i=0;i<s;i++)s4[i+1]=(s4[i+1]+s1[i])%mod;
	fz1(l,mid);fz1(mid+1,r);
}
void fz2(int l,int r)
{
	if(l>=r)return;
	int mid=(l+r)>>1;
	int m1=0,m2=0;
	for(int i=l;i<=mid;i++)m1=max(len[i]+i-l,m1);
	for(int i=mid+1;i<=r;i++)m2=max(len[i]+r-i,m2);
	for(int i=0;i<=m1;i++)s1[i]=0;
	for(int i=0;i<=m2;i++)s2[i]=0;
	for(int i=l;i<=mid;i++)
	for(int j=0;j<=len[i];j++)s1[i-l+j]+=sth[j+lb[i]];
	for(int i=mid+1;i<=r;i++)
	for(int j=0;j<=len[i];j++)s2[r-i+j]+=sth[j+lb[i]];
	int s=1;while(s<=m1+m2)s<<=1;
	for(int i=m1+1;i<s;i++)s1[i]=0;
	for(int i=m2+1;i<s;i++)s2[i]=0;
	dft(s,s1,1);dft(s,s2,1);for(int i=0;i<s;i++)s1[i]=2ll*s1[i]*s2[i]%mod;dft(s,s1,-1);
	for(int i=0;i<s;i++)s4[i+le-r+l]=(s4[i+le-r+l]+s1[i])%mod;
	fz2(l,mid);fz2(mid+1,r);
}
int main()
{
	scanf("%d",&n);m=n;
	for(int i=1;i<=m;i++)scanf("%d%d",&a,&b),adde(a+1,b+1);
	{
		dfs0(1,0);
		for(int i=1;i<=le;i++)
		{
			vis[c[i==1?le:i-1]]=1,vis[c[i==le?1:i+1]]=1;vis[c[i]]=0;
			ds[0]=-1;mx2=0;
			dfs2(c[i],0);
			lb[i]=++ct2;
			len[i]=mx2;
			ct2+=mx2;
			for(int j=0;j<=mx2;j++)sth[j+lb[i]]=s2[j],s5[j]+=s2[j],s3[j]=s2[j],s2[j]=0;
			int l=1;while(l<=mx2*2)l<<=1;
			for(int j=mx2+1;j<l;j++)s3[j]=0;
			dft(l,s3,1);for(int j=0;j<l;j++)s3[j]=1ll*s3[j]*s3[j]%mod;dft(l,s3,-1);
			for(int j=0;j<l;j++)s4[j+le-1]=(s4[j+le-1]+s3[j])%mod,s3[j]=0;
			dfs3(c[i]);
		}
		fz1(1,le);fz2(1,le);
		int l=1;while(l<=n*2)l<<=1;
		dft(l,s5,1);for(int i=0;i<l;i++)s5[i]=1ll*s5[i]*s5[i]%mod;dft(l,s5,-1);
		for(int j=0;j<l;j++)s4[j+le-1]=(s4[j+le-1]-s5[j]+mod)%mod;
		double ans=0;
		for(int i=1;i<=n;i++)
		ans=(ans+1.0*(s4[i]>1e7?s4[i]-mod:s4[i])/(i+1));
		printf("%.10lf\n",ans+n);
	}
}