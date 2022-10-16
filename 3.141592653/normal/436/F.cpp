#include<cstdio>
#include<vector>
std::vector<int>v[111111];
typedef long long ll;
int n,ctb,w,a[111111],b[111111];
const int blk=315;
void emax(int&x,int y){x<y?x=y:0;}
inline int bel(int x){return (x-1)/blk+1;}
inline int Lol(int x){return (x-1)*blk+1;}
inline int Rol(int x){return x*blk;}
struct Block
{
	ll Dat[444],Max,MxId;
	int crash,delt,L;
	void rebuild()
	{
		Max=Dat[1],MxId=L,delt=0,crash=1e9;
		register int i,t=1;
		for(i=2;i<=blk;i++)if(Dat[i]>=Max)Max=Dat[i],MxId=L+i-1,t=i;
		for(i=t+1;i<=blk;i++)
		{
			ll d=i-t,dv=Max-Dat[i],rc=(dv-1)/d+1;
			if(crash>rc)crash=rc;
		}
	}
	void run()
	{
		delt++;
		if(delt==crash)
		{
			for(register int i=1;i<=blk;i++)Dat[i]+=delt*1ll*(L+i-1);
			rebuild();
		}else Max+=MxId;
	}
	void push(int rd)
	{
		for(register int i=1;i<=blk;i++)Dat[i]+=(delt+(i<=rd))*1ll*(L+i-1);
		rebuild();
	}
}B[444];
void ins(int x)
{
	register int i;
	for(i=1;i<bel(x);i++)B[i].run();
	B[i].push(x-(i-1)*blk);
}
void qmax(ll delt)
{
	ll mxv=0;int mxp=0;
	register int i;
	for(i=1;i<=ctb;i++)
		if(B[i].Max>mxv)mxv=B[i].Max,mxp=B[i].MxId;
	printf("%lld %d\n",delt+mxv,mxp);
}
int main()
{
	scanf("%d%d",&n,&w);
	register int i,ma=0,mb=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i),v[b[i]].push_back(a[i]),emax(mb,b[i]),emax(ma,a[i]);
	for(ctb=bel(ma),i=1;i<=ctb;i++)B[i].L=Lol(i),B[i].rebuild();
	int cp=n;
	for(i=0;i<=mb+1;i++)
	{
		if(!i)puts("0 998244353");
		else qmax(cp*1ll*i*w);
		for(int t:v[i])ins(t),cp--;
	}
}
/*
Please don't let me down.
*/