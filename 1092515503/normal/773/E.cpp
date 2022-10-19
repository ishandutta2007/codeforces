#include<bits/stdc++.h>
using namespace std;
int n,rt,cnt;
mt19937 rnd(17680321);
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct Treap{int ch[2],sz,rd,val,mn;}t[500100];
void pushup(int x){
	t[x].sz=t[lson].sz+t[rson].sz+1;
	t[x].mn=min(min(t[lson].mn+1,t[x].val)+t[rson].sz,t[rson].mn);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd)return t[x].ch[1]=merge(t[x].ch[1],y),pushup(x),x;
	else return t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y),y;
}
void splitbyval(int x,int K,int&u,int&v){
	if(!x)return u=v=0,void();
	if(t[x].val<=K)u=x,splitbyval(rson,K,rson,v);
	else v=x,splitbyval(lson,K,u,lson);
	pushup(x);
}
void splitbysz(int x,int K,int&u,int&v){
	if(!x)return u=v=0,void();
	if(t[lson].sz>=K)v=x,splitbysz(lson,K,u,lson);
	else u=x,splitbysz(rson,K-t[lson].sz-1,rson,v);
	pushup(x);
}
int retrieve(int x,int sz){
	if(!x)return -1;
	if(t[x].val>=-(sz+t[lson].sz+1)){
		int ret=retrieve(lson,sz);
		return ret==-1?sz+t[lson].sz+1:ret;
	}
	return retrieve(rson,sz+t[lson].sz+1);
}
void Insert(int K){
	int u,v;
	splitbyval(rt,K,u,v);
	int x=++cnt;t[x].mn=t[x].val=K,t[x].sz=1,t[x].rd=rnd()&((1<<30)-1);
	rt=merge(merge(u,x),v);
}
int Calc(){
	int P=retrieve(rt,0);
	if(P==-1)return -t[rt].sz;
	int u,v;
	splitbysz(rt,P-1,u,v);
	int ret=min((1-P)+t[v].sz,t[v].mn);
	rt=merge(u,v);
	return ret;
}
int main(){
	t[0].mn=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),Insert(x),printf("%d\n",Calc());
	return 0;
}
/*
3
-5 -3 -14
*/