#include<cstdio>
typedef long long ll;
ll n,g,r,m;
ll dp[111111],el[111111],sm[111111];
struct seg
{
	ll l,r;
	int v;
	seg*ls,*rs;
	seg(ll lp=0,ll rp=0,int vp=0){l=lp,r=rp,ls=0,rs=0,v=vp;}
	void push()
	{
		if(!ls)ls=new seg(l,(l+r>>1));
		if(!rs)rs=new seg((l+r>>1)+1,r);
		ls->v=rs->v=v;
		v=-1;
	}
}*root;
inline void insert(ll lq,ll rq,int vq,seg*now=root)
{
	if(now->l>rq||now->r<lq)return;
	if(now->l>=lq&&now->r<=rq){now->v=vq;return;}
	if(~now->v)now->push();
	insert(lq,rq,vq,now->ls),insert(lq,rq,vq,now->rs);
}
inline int query(ll pos,seg*now=root)
{
	if(now->v!=-1)return now->v;
	if(now->ls->r>=pos)return query(pos,now->ls);
	else return query(pos,now->rs);
}
int main()
{
	scanf("%lld%lld%lld",&n,&g,&r),m=g+r;
	root=new seg(0,m-1);
	register int i;
	for(i=0;i<=n;i++)scanf("%d",&el[i]);sm[0]=el[0];
	for(i=1;i<=n;i++)sm[i]=sm[i-1]+el[i];
	ll dt=0;
	for(i=n;i;i--)
	{
		int pos=query(dt);
		if(!pos)dp[i]=sm[n]-sm[i-1];
		else dp[i]=dp[pos]+((sm[pos-1]-sm[i-1])/m+1)*m;
		ll lt=(g+dt)%m,rt=(dt+m-1)%m;
		if(lt<=rt)insert(lt,rt,i);
		else insert(0,rt,i),insert(lt,m-1,i);
		(dt+=el[i-1])%=m;
	}
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		ll x;
		scanf("%lld",&x);
		ll ans=x;(x+=dt)%=m;
		int pos=query(x);
		if(!pos)printf("%lld\n",ans+sm[n]);
		else printf("%lld\n",dp[pos]+((sm[pos-1]+ans)/m+1)*m);
	}
}