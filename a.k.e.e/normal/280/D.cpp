#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
const int MAXN=100005,INF=0x3f3f3f3f;
inline void chkmax(int &x,int y){x<y?(x=y):0;}

int n,a[MAXN];
struct Node
{
	int f[23],rf[23],lf[23],sf[23];
	Node(int x=-INF)
	{
		f[0]=lf[0]=rf[0]=sf[0]=0;
		for(int i=1;i<=20;i++)
		{
			f[i]=max(x,0);
			lf[i]=rf[i]=sf[i]=x;
		}
	}
}st[MAXN<<2|1];
Node update(Node ls,Node rs)
{
	Node ans;
	for(register int k=1;k<=20;k++)
		for(register int i=0;i<=k;i++)
		{
			chkmax(ans.f[k],ls.f[i]+rs.f[k-i]);
			if(i)chkmax(ans.f[k],ls.rf[i]+rs.lf[k-i+1]);
			if(i)chkmax(ans.lf[k],ls.lf[i]+rs.f[k-i]);
			if(i)chkmax(ans.lf[k],ls.sf[i]+rs.lf[k-i+1]);
			if(i<k)chkmax(ans.rf[k],ls.f[i]+rs.rf[k-i]);
			if(i)chkmax(ans.rf[k],ls.rf[i]+rs.sf[k-i+1]);
			if(i && i<k)chkmax(ans.sf[k],ls.lf[i]+rs.rf[k-i]);
			if(i)chkmax(ans.sf[k],ls.sf[i]+rs.sf[k-i+1]);
		}
	return ans;
}
void build(int id,int l,int r)
{
	if(l==r){st[id]=Node(a[l]);return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	st[id]=update(st[id<<1],st[id<<1|1]);
}
void modify(int id,int l,int r,int x,int c)
{
	if(l==r){st[id]=Node(c);return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(id<<1,l,mid,x,c);
	else modify(id<<1|1,mid+1,r,x,c);
	st[id]=update(st[id<<1],st[id<<1|1]);
}
Node query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return st[id];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return update(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,op,u,v,w;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&Q);
    while(Q--)
    {
    	scanf("%d",&op);
    	if(!op)
    	{
    		scanf("%d%d",&u,&w);
    		modify(1,1,n,u,w);
    	}
    	else
    	{
    		scanf("%d%d%d",&u,&v,&w);
    		printf("%d\n",query(1,1,n,u,v).f[w]);
    	}
    }
    return 0;
}