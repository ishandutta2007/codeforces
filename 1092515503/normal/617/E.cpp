#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,cnt[1<<20],num[100100],BBB,BLK[100100];
ll ans,res[100100];
struct node{
	int l,r,id;
	friend bool operator <(const node &x,const node &y){
		if(BLK[x.l]!=BLK[y.l])return BLK[x.l]<BLK[y.l];
		return BLK[x.l]&1?x.r<y.r:x.r>y.r;
	}
}q[100100];
void Push(int pos){
	ans+=cnt[num[pos]^k];
	cnt[num[pos]]++;
}
void Pop(int pos){
	cnt[num[pos]]--;
	ans-=cnt[num[pos]^k];
}
int main(){
	scanf("%d%d%d",&n,&m,&k),BBB=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]),BLK[i]=i/BBB;
		num[i]^=num[i-1];
	}
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].l--,q[i].id=i;
	sort(q+1,q+m+1);
	Push(1);
	for(int i=1,L=1,R=1;i<=m;i++){
		while(L>q[i].l)Push(--L);
		while(R<q[i].r)Push(++R);
		while(L<q[i].l)Pop(L++);
		while(R>q[i].r)Pop(R--);
		res[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",res[i]);
	return 0;
}
/*
50 2 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

17 35

3 35
*/