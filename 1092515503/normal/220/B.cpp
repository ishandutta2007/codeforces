#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[100100],num[100100],BBB,BLK[100100],ans,res[100100];
vector<int>v;
struct node{
	int l,r,id;
	friend bool operator <(const node &x,const node &y){
		if(BLK[x.l]!=BLK[y.l])return BLK[x.l]<BLK[y.l];
		return BLK[x.l]&1?x.r<y.r:x.r>y.r;
	}
}q[100100];
void Push(int pos){
	ans-=(cnt[num[pos]]==v[num[pos]]);
	cnt[num[pos]]++;
	ans+=(cnt[num[pos]]==v[num[pos]]);
}
void Pop(int pos){
	ans-=(cnt[num[pos]]==v[num[pos]]);
	cnt[num[pos]]--;
	ans+=(cnt[num[pos]]==v[num[pos]]);
}
int main(){
	scanf("%d%d",&n,&m),BBB=sqrt(n);
	for(int i=0;i<n;i++)scanf("%d",&num[i]),BLK[i]=i/BBB,v.push_back(num[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=0;i<n;i++)num[i]=lower_bound(v.begin(),v.end(),num[i])-v.begin();
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].l--,q[i].r--,q[i].id=i;
	sort(q+1,q+m+1);
	Push(1);
	for(int i=1,L=1,R=1;i<=m;i++){
		while(L>q[i].l)Push(--L);
		while(R<q[i].r)Push(++R);
		while(L<q[i].l)Pop(L++);
		while(R>q[i].r)Pop(R--);
		res[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}