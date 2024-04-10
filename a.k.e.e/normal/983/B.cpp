#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=5005;

int n,d[MAXN][MAXN];
int Max[MAXN][MAXN<<1];

void build(int tr,int id,int l,int r)
{
	if(l==r)
	{
		Max[tr][id]=d[l][tr];
		return;
	}
	int mid=(l+r)>>1;
	build(tr,id<<1,l,mid);
	build(tr,id<<1|1,mid+1,r);
	Max[tr][id]=max(Max[tr][id<<1],Max[tr][id<<1|1]);
}

int query(int tr,int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)
		return Max[tr][id];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(tr,id<<1,l,mid,ql,qr);
	if(ql>mid)return query(tr,id<<1|1,mid+1,r,ql,qr);
	return max(query(tr,id<<1,l,mid,ql,mid),
		query(tr,id<<1|1,mid+1,r,mid+1,qr));
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&d[i][i]);
    for(int k=2;k<=n;k++)
    	for(int i=1;i+k-1<=n;i++)
    		d[i][i+k-1]=d[i][i+k-2]^d[i+1][i+k-1];
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    		d[i][j]=max(d[i][j-1],d[i][j]);
    for(int j=1;j<=n;j++)
    	for(int i=j-1;i>0;i--)
    		d[i][j]=max(d[i][j],d[i+1][j]);
    scanf("%d",&Q);
    while(Q--)
    {
    	scanf("%d%d",&l,&r);
    	printf("%d\n",d[l][r]);
    }
    return 0;
}