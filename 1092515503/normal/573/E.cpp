#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res;
int n,a[100100],rt,cnt;
struct Treap{
	int ch[2],sz,rd;
	ll val,tag,dif;
}t[100100];
#define lson t[x].ch[0]
#define rson t[x].ch[1]
void pushup(int x){t[x].sz=t[lson].sz+t[rson].sz+1;}
void ADD(int x,ll val,ll dif){t[x].val+=val,t[x].tag+=val,t[x].dif+=dif;}
void pushdown(int x){
	if(lson)ADD(lson,t[x].tag-t[x].dif*(t[t[lson].ch[1]].sz+1),t[x].dif);
	if(rson)ADD(rson,t[x].tag+t[x].dif*(t[t[rson].ch[0]].sz+1),t[x].dif);
	t[x].dif=t[x].tag=0;
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd){pushdown(x),t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{pushdown(y),t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void split(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	pushdown(x);
	if(t[lson].sz>=k)v=x,split(lson,k,u,lson);
	else u=x,split(rson,k-t[lson].sz-1,rson,v);
	pushup(x);
}
ll kth(int k){
	if(!k)return 0;
	int a,b,c;
	split(rt,k-1,a,b);
	split(b,1,b,c);
	ll ret=t[b].val;
	rt=merge(merge(a,b),c);
	return ret;
}
void Insert(int k,ll y){//insert an element and let it be the k-th one
	int a,b;
	split(rt,k-1,a,b);
	int x=++cnt;
	t[x].val=y,t[x].rd=rand()*rand();
	rt=merge(merge(a,x),b);
}
void Add(int k,int y){
	int a,b;
	split(rt,k-1,a,b);
	t[b].val+=1ll*(k+t[t[b].ch[0]].sz)*y;
	t[b].tag+=1ll*(k+t[t[b].ch[0]].sz)*y;
	t[b].dif+=y;
	rt=merge(a,b);
}
void Iterate(int x){
	if(!x)return;
	pushdown(x),Iterate(lson),Iterate(rson);
	res=max(res,t[x].val);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(kth(mid-1)+1ll*a[i]*mid>=kth(mid))r=mid;
			else l=mid+1;
		}
		Insert(r,kth(r-1));
		Add(r,a[i]);
	}
	Iterate(rt);
	printf("%lld\n",res);
	return 0;
}
/*
5
-2 -8 0 5 -3
6
-1 2 -3 4 -5 6
*/