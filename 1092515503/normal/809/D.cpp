#include<bits/stdc++.h>
using namespace std;
#define lson t[x].ch[0]
#define rson t[x].ch[1]
int cnt,n,root;
struct treap{
	int ch[2],val,rad,sz,tag;
}t[300100];
int newnode(int val){
	cnt++,t[cnt].rad=rand()*rand(),t[cnt].sz=1,t[cnt].val=val;
	return cnt;
}
void pushup(int x){
	t[x].sz=t[lson].sz+t[rson].sz+1;
}
void ADD(int x,int val){
	t[x].tag+=val,t[x].val+=val;
}
void pushdown(int x){
	if(!x)return;
	if(lson)ADD(lson,t[x].tag);
	if(rson)ADD(rson,t[x].tag);
	t[x].tag=0;
}
int merge(int x,int y){
	if(!y)return x;
	if(!x)return y;
	pushdown(x),pushdown(y);
	if(t[x].rad>t[y].rad){t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void split(int x,int val,int &u,int &v){//u:the subtree which <val;v:the subtree which >=val
	if(!x){u=v=0;return;}
	pushdown(x);
	if(t[x].val<val)u=x,split(rson,val,rson,v);
	else v=x,split(lson,val,u,lson);
	pushup(x);
}
int kth(int x,int k){
	if(!k)return 0;
	while(true){
		pushdown(x);
		if(t[lson].sz>=k)x=lson;
		else if(t[lson].sz+1<k)k-=t[lson].sz+1,x=rson;
		else return x;
	}
}
int suf(int val){//the largest node >= val
	int u=0,v=0,res;
	split(root,val,u,v);
	if(!v)return 0;
	res=kth(v,1);
	root=merge(u,v);
	return res;
}
void ins(int val){
	int a=0,b=0;
	split(root,val,a,b);
	root=merge(a,merge(newnode(val),b));
}
void del(int val){
	int a=0,b=0,c=0,d=0;
	split(root,val,a,b);
	split(b,val+1,c,d);
	c=merge(t[c].ch[0],t[c].ch[1]);
	root=merge(a,merge(c,d));
} 
void iterate(int x){
	if(!x)return;
	pushdown(x),iterate(lson),printf("%d ",t[x].val),iterate(rson);
}
void add(int l,int r){
	int a=0,b=0,c=0,d=0;
	split(root,l,a,b);
	split(b,r,c,d);
	if(c)ADD(c,1);
//	printf("A "),iterate(a),puts("");
//	printf("B "),iterate(c),puts("");
//	printf("C "),iterate(d),puts("");
	root=merge(a,merge(c,d));
}
int main(){
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		if(i==1){ins(l);continue;}
		int x=suf(r);
		add(l,r);
		if(x)del(t[x].val);
		ins(l);
	}
	printf("%d\n",t[root].sz);
	return 0;
}