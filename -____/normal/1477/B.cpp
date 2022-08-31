#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
const int M = 1<<19;
int n,q,l[N],r[N];
char s[N],f[N];
int t[M];
void modify(int L,int R,int x,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		t[k]=(r-l+1)*x;
		return;
	}
	int h=l+r>>1;
	if(t[k]==0)
		t[k<<1]=0,t[k<<1|1]=0;
	if(t[k]==r-l+1)
		t[k<<1]=h-l+1,t[k<<1|1]=r-h;
	if(L<=h)
		modify(L,R,x,k<<1,l,h);
	if(h<R)
		modify(L,R,x,k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1,o=0;
	if(t[k]==0)
		t[k<<1]=0,t[k<<1|1]=0;
	if(t[k]==r-l+1)
		t[k<<1]=h-l+1,t[k<<1|1]=r-h;
	if(L<=h)
		o+=query(L,R,k<<1,l,h);
	if(h<R)
		o+=query(L,R,k<<1|1,h+1,r);
	return o;
}
int main(){
	int T,i,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s%s",&n,&q,s+1,f+1);
		for(i=1;i<=q;i++)
			scanf("%d%d",l+i,r+i);
		modify(1,n,0);
		for(i=1;i<=n;i++)
			if(f[i]=='1')
				modify(i,i,1);
		z=1;
		for(i=q;i>=1;i--){
			x=query(l[i],r[i]);
			y=r[i]-l[i]+1-x;
			if(x==y){
				z=0;
				break;
			}
			if(x<y)
				modify(l[i],r[i],0);
			else
				modify(l[i],r[i],1);
		}
		for(i=1;i<=n;i++)
			if((s[i]-'0')!=query(i,i))
				z=0;
		if(z)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}