#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=22;
int n,a[N],b[N],c[N],stk[N],nxt[N],pre[N],f[N],nn;
int lowbit(int x){return x&-x;}
void modify(int x,int y){while(x<=(n<<1))c[x]=min(c[x],y),x+=lowbit(x);}
int query(int x){int s=nn+1;while(x)s=min(s,c[x]),x-=lowbit(x);return s; }
int main()
{
	cin>>n,nn=3*n;
	memset(c,0x3f,sizeof(c));
	int cnt=0;
	for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i],a[i+(n<<1)]=a[i],b[++cnt]=a[i],b[++cnt]=a[i]*2;
	int top=0;
	for(int i=nn;i>=1;i--)
	{
		while(top&&a[i]>a[stk[top]])top--;
		!top?nxt[i]=nn+1:nxt[i]=stk[top];
		stk[++top]=i;
	}
	sort(b+1,b+cnt+1);
	int m=unique(b+1,b+cnt+1)-b-1;
	top=0;
	for(int i=nn;i>=1;i--)
	{
		cnt=top;
		int t=query(lower_bound(b+1,b+m+1,a[i])-b-1);
		pre[i]=t;
		modify(lower_bound(b+1,b+m+1,a[i]<<1)-b,i);
	}
	for(int i=nn;i>=1;i--){
		f[i]=1;
		if(pre[i]>=nxt[i])f[i]=f[nxt[i]]+nxt[i]-i;
		else f[i]=pre[i]-i;
	}
	for(int i=1;i<=n;i++)
		if(f[i]>=n*2)cout<<"-1 ";
		else cout<<f[i]<<" ";
	return 0;
}