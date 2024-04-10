#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num[200100],BBB,cnt[1001000],res[200100],ans;
struct node{
	int l,r,id;
	friend bool operator <(const node &x,const node &y){
		if(x.r/BBB!=y.r/BBB)return x.r/BBB<y.r/BBB;
		return (x.r/BBB)&1?x.l<y.l:x.l>y.l;
	}
}q[200100];
void Push(int x){
	ans-=cnt[num[x]]*cnt[num[x]]*num[x];
	cnt[num[x]]++;
	ans+=cnt[num[x]]*cnt[num[x]]*num[x];
}
void Pop(int x){
	ans-=cnt[num[x]]*cnt[num[x]]*num[x];
	cnt[num[x]]--;
	ans+=cnt[num[x]]*cnt[num[x]]*num[x];
}
signed main(){
	scanf("%lld%lld",&n,&m),BBB=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	for(int i=1;i<=m;i++)scanf("%lld%lld",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1),Push(1);
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
3 2
1 2 1
1 2
1 3
*/