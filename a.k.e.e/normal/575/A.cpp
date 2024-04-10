#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005;
typedef pair<ll,ll> pll;

int n,m,MOD,q;
ll k,a[MAXN];

inline int dmy(int x)
	{return x<0?x+MOD:(x>=MOD?x-MOD:x);}
ll qmi(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1,x=x*x%MOD)
		if(y&1)ans=ans*x%MOD;
	return ans;
}

struct Matrix
{
	ll a[2][2];
	Matrix(){memset(a,0,sizeof(a));}
	Matrix(ll a00,ll a01,ll a10,ll a11)
		{a[0][0]=dmy(a00),a[0][1]=dmy(a01),a[1][0]=dmy(a10),a[1][1]=dmy(a11);}
	Matrix operator *(const Matrix &b)const
	{
		Matrix c;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					(c.a[i][j]+=a[i][k]*b.a[k][j])%=MOD;
		return c;
	}
};
Matrix qmi(Matrix x,ll k)
{
	Matrix ans(1,0,0,1);
	for(;k;k>>=1,x=x*x)
		if(k&1)ans=ans*x;
	return ans;
}
struct Data
{
	int op;ll whi,pos,val;
	Data(){}
	Data(int op,ll x,ll val):op(op),whi(x/n),pos(x%n),val(val){}
	inline bool operator <(const Data &b)const{return whi<b.whi;}
};

Matrix mtx[MAXN],cur[MAXN],sum[MAXN<<2|1];
Data d[MAXN];
void build(int id,int l,int r)
{
	if(l==r){sum[id]=mtx[l];return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	sum[id]=sum[id<<1]*sum[id<<1|1];
}
void modify(int id,int l,int r,int x,Matrix c)
{
	if(l==r){sum[id]=c;return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(id<<1,l,mid,x,c);
	else modify(id<<1|1,mid+1,r,x,c);
	sum[id]=sum[id<<1]*sum[id<<1|1];
}
Matrix query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return sum[id];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return query(id<<1,l,mid,ql,mid)*query(id<<1|1,mid+1,r,mid+1,qr);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	ll x,y;
	readint(k);readint(MOD);
	if(!k)return 0*printf("0\n");
	readint(n);
	for(int i=0;i<n;++i)readint(a[i]);a[n]=a[0];
	for(int i=0;i<n;++i)mtx[i]=cur[i]=Matrix(0,a[i],1,a[i+1]);
	readint(m);
	for(int i=1;i<=m;++i)
	{
		readint(x),readint(y);
		if(x>k)continue;
		if(x<k)d[++q]=Data(0,x,y);
		d[++q]=Data(1,x-1,y);
	}
	sort(d+1,d+q+1);
	if(d[q].whi<(k-1)/n)d[++q]=Data(0,k-1,a[(k-1)%n]);
	d[0].whi=-1;
	
	build(1,0,n-1);
	Matrix ans(1,0,0,1);
	int las=1;
	for(int i=1;i<=q;++i)
	{
		if(d[i].whi>d[i-1].whi)
		{
			if(d[i-1].whi>=0)ans=ans*sum[1];
			for(;las<i;++las)modify(1,0,n-1,d[las].pos,cur[d[las].pos]=mtx[d[las].pos]);
			ans=ans*qmi(sum[1],d[i].whi-d[i-1].whi-1);
		}
		cur[d[i].pos].a[d[i].op][1]=d[i].val;
		modify(1,0,n-1,d[i].pos,cur[d[i].pos]);
	}
	ans=ans*query(1,0,n-1,0,(k-1)%n);
	printf("%lld\n",ans.a[1][0]);
	return 0;
}