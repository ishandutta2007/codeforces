#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,d,a[N],dp[N];
struct Seg_Tree{
	bool q[N<<2];
	void modify(int l,int r,int pos,int x){
		q[x]=1; if(l==r)return;
		int m=l+r>>1;
		if(pos<=m)modify(l,m,pos,x<<1);
		else modify(m+1,r,pos,x<<1|1);
	}
	bool query(int l,int r,int ql,int qr,int x){
		if(ql<=l&&r<=qr)return q[x];
		bool ans=0; int m=l+r>>1;
		if(ql<=m)ans=ans|query(l,m,ql,qr,x<<1);
		if(m<qr)ans=ans|query(m+1,r,ql,qr,x<<1|1);
		return ans;
	}
}t;
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1); t.modify(0,n,0,1);
	for(int i=1;i<=n;i++){
		int pos=lower_bound(a+1,a+n+1,a[i]-d)-a;
		if(pos<=i-k+1&&t.query(0,n,pos-1,i-k,1))t.modify(0,n,i,1);
	}
	if(t.query(0,n,n,n,1))puts("YES");
	else puts("NO");
	return 0;
}