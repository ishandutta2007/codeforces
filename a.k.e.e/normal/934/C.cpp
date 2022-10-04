#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=2005;

int n,a[MAXN],f1[MAXN],d[MAXN][MAXN];
int s2[MAXN<<2|1],s1[MAXN<<2],s[MAXN<<2];

struct Node
{
	int s1,s2,s;
	Node(int s1=0,int s2=0,int s=0):s1(s1),s2(s2),s(s){}
};

void build(int id,int l,int r)
{
	if(l==r)
	{
		if(a[l]==1)s1[id]=1;
		else s2[id]=1;
		s[id]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	s2[id]=s2[id<<1]+s2[id<<1|1];
	s1[id]=s1[id<<1]+s1[id<<1|1];
	s[id]=max(s[id<<1]+s1[id<<1|1],s2[id<<1]+s[id<<1|1]);
}

Node query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)
		return Node(s1[id],s2[id],s[id]);
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	Node lt=query(id<<1,l,mid,ql,mid),rt=query(id<<1|1,mid+1,r,mid+1,qr);
	return Node(lt.s1+rt.s1,lt.s2+rt.s2,max(lt.s+rt.s1,lt.s2+rt.s));
}

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
    	if(a[i]==1)f1[i]=f1[i-1]+1;
    	else f1[i]=f1[i-1];
    }
    build(1,1,n);
    int ans=0;
    for(int l=1;l<=n;l++)
    	for(int r=l;r<=n;r++)
    	{
    		Node p=query(1,1,n,l,r);
    		//cout<<l<<" "<<r<<":"<<p.s1<<" "<<p.s2<<" "<<p.s<<endl;
    		ans=max(ans,f1[l-1]+p.s+n-r-f1[n]+f1[r]);
    	}
    cout<<ans<<endl;
    
    return 0;
}