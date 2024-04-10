#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
inline int rd()
{
	int x=0;char c=getchar();while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();return x;
}
inline void prt(int x){if(x>9)prt(x/10);putchar(48+x%10);}
const int N=1000005;
int n,m,o,a[N],b[N],qo[N],qp[N],qx[N],t[N],mx[N<<2],tg[N<<2];
void build(int x,int l,int r)
{
	mx[x]=0;if(l==r)return;
	int mid=l+r>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);
}
inline void cov(int x,int v){mx[x]+=v;tg[x]+=v;}
inline void dn(int x){if(tg[x]){cov(x<<1,tg[x]);cov(x<<1|1,tg[x]);tg[x]=0;}}
void upd(int x,int l,int r,int tl,int tr,int v)
{
	if(tl<=l&&r<=tr){cov(x,v);return;}
	int mid=l+r>>1;dn(x);
	if(tl<=mid)upd(x<<1,l,mid,tl,tr,v);
	if(tr>mid)upd(x<<1|1,mid+1,r,tl,tr,v);
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int qry(int x,int l,int r)
{
	if(l==r)return mx[x]>0?t[l]:-1;
	int mid=l+r>>1;dn(x);
	if(mx[x<<1|1]>0)return qry(x<<1|1,mid+1,r);
	return qry(x<<1,l,mid);
}
int main()
{
	n=rd();m=rd();
	rep(i,1,n)a[i]=rd(),t[++o]=a[i];
	rep(i,1,m)b[i]=rd(),t[++o]=b[i];
	int Q=rd();
	rep(i,1,Q){qo[i]=rd();qp[i]=rd();qx[i]=rd();t[++o]=qx[i];}
	sort(t+1,t+o+1);o=unique(t+1,t+o+1)-t-1;
	rep(i,1,n)a[i]=lower_bound(t+1,t+o+1,a[i])-t;
	rep(i,1,m)b[i]=lower_bound(t+1,t+o+1,b[i])-t;
	rep(i,1,Q)qx[i]=lower_bound(t+1,t+o+1,qx[i])-t;
	rep(i,1,n)upd(1,1,o,1,a[i],1);
	rep(i,1,m)upd(1,1,o,1,b[i],-1);
	rep(i,1,Q)
	{
		int op=qo[i],p=qp[i],x=qx[i];
		if(op==1){upd(1,1,o,1,a[p],-1);a[p]=x;upd(1,1,o,1,a[p],1);}
		else{upd(1,1,o,1,b[p],1);b[p]=x;upd(1,1,o,1,b[p],-1);}
		printf("%d\n",qry(1,1,o));
	}
	return 0;
}