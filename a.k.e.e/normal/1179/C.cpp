#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005,A=1000000;

int n,m,a[MAXN],b[MAXN],Min[A<<2|63],lazy[A<<2|63];
inline void pushdown(int id)
{
	if(!lazy[id])return;
	Min[id]+=lazy[id];
	lazy[id<<1|1]+=lazy[id];lazy[id<<1]+=lazy[id];
	lazy[id]=0; 
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql && r==qr){lazy[id]+=c;return;}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
	Min[id]=min(Min[id<<1]+lazy[id<<1],Min[id<<1|1]+lazy[id<<1|1]);
}
int query(int id,int l,int r)
{
	if(Min[id]+lazy[id]>=0)return -1;
	if(l==r)return l;
	pushdown(id);
	int mid=(l+r)>>1;
	if(Min[id<<1|1]+lazy[id<<1|1]<0)return query(id<<1|1,mid+1,r);
	return query(id<<1,l,mid);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,op,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);modify(1,1,A,1,a[i],-1);}
    for(int i=1;i<=m;i++){scanf("%d",&b[i]);modify(1,1,A,1,b[i],1);}
    scanf("%d",&Q);
    while(Q--)
    {
    	scanf("%d%d%d",&op,&u,&v);
    	if(op==1){modify(1,1,A,1,a[u],1);modify(1,1,A,1,a[u]=v,-1);}
	    else {modify(1,1,A,1,b[u],-1);modify(1,1,A,1,b[u]=v,1);}
    	printf("%d\n",query(1,1,A));
    }
    return 0;
}