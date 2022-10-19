#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,root[5],cnt,bin[100100],tp;
struct treap{
	int lson,rson,val,rd,sz;
	ll sum;
}t[100100];
int newnode(int val){
	int x=(tp?bin[tp--]:++cnt);
	t[x].lson=t[x].rson=0,t[x].sum=t[x].val=val,t[x].rd=rand()*rand(),t[x].sz=1;
	return x;
}
void pushup(int x){
	t[x].sum=t[x].val,t[x].sz=1;
	if(t[x].lson)t[x].sum+=t[t[x].lson].sum,t[x].sz+=t[t[x].lson].sz; 
	if(t[x].rson)t[x].sum+=t[t[x].rson].sum,t[x].sz+=t[t[x].rson].sz;
}
void split(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	if(t[x].val<=k)u=x,split(t[x].rson,k,t[x].rson,v);
	else v=x,split(t[x].lson,k,u,t[x].lson);
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd<t[y].rd){t[x].rson=merge(t[x].rson,y),pushup(x);return x;}
	else{t[y].lson=merge(x,t[y].lson),pushup(y);return y;}
}
int main(){
	srand(19260817);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		char s[10];
		scanf("%s",s);
		if(s[0]=='a'){
			scanf("%d",&x);
			int u[5],v[5],sz=1;
			for(int i=0;i<5;i++)split(root[i],x,u[i],v[i]),sz+=t[u[i]].sz,root[i]=u[i];
			x=newnode(x);
			root[sz%5]=merge(root[sz%5],x);
			for(int i=0;i<5;i++)root[i]=merge(root[i],v[(i+4)%5]);
		}
		if(s[0]=='d'){
			scanf("%d",&x);
			int u[5],v[5],w[5];
			for(int i=0;i<5;i++)split(root[i],x,u[i],v[i]),split(u[i],x-1,root[i],w[i]);
			for(int i=0;i<5;i++)root[i]=merge(root[i],v[(i+1)%5]);
		}
		if(s[0]=='s')printf("%lld\n",t[root[3]].sum);
	}
	return 0;
}