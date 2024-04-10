#include<bits/stdc++.h>
using namespace std;
int n,m,rt;
pair<int,int>p[200100],q[200100];
struct Treap{
	int ch[2],rd,val,tot,tagv,tagt;
}t[200100];
#define lson t[x].ch[0]
#define rson t[x].ch[1]
void SUB(int x,int y){t[x].val-=y,t[x].tagv+=y;}
void ADD(int x,int y=1){t[x].tot+=y,t[x].tagt+=y;}
void pushdown(int x){
	if(lson)SUB(lson,t[x].tagv),ADD(lson,t[x].tagt);
	if(rson)SUB(rson,t[x].tagv),ADD(rson,t[x].tagt);
	t[x].tagt=t[x].tagv=0;
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd){pushdown(x),t[x].ch[1]=merge(t[x].ch[1],y);return x;}
	else{pushdown(y),t[y].ch[0]=merge(x,t[y].ch[0]);return y;}
}
void split(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	pushdown(x);
	if(t[x].val<k)u=x,split(rson,k,rson,v);
	else v=x,split(lson,k,u,lson);
}
void reset(int &RT,int x){
	if(!x)return;
	pushdown(x);
	int a,b;
	split(RT,t[x].val,a,b);
	reset(a,lson),reset(b,rson);
	lson=rson=0;
	RT=merge(merge(a,x),b);
}
void func(int k){
	int a,b,c;
	split(rt,k,a,b);
	if(b)ADD(b),SUB(b,k);
	split(b,2*k,b,c);
	reset(a,b);
	rt=merge(a,c);
}
void iterate(int x){
	if(!x)return;
	pushdown(x);
	iterate(lson),iterate(rson);
}
int stk[200100],tp;
int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
int main(){
	m=read();
	for(int i=1;i<=m;i++)p[i].second=read(),p[i].first=-read();sort(p+1,p+m+1);
	n=read();for(int i=1;i<=n;i++)q[i].first=t[i].val=read(),q[i].second=i,t[i].rd=rand()*rand();
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++){
		int x=q[i].second;
		while(tp&&t[stk[tp]].rd<t[x].rd)t[x].ch[0]=stk[tp--];
		if(tp)t[stk[tp]].ch[1]=x;
		stk[++tp]=x;
	}rt=stk[1];
	for(int i=1;i<=m;i++)func(p[i].second);
	iterate(rt);for(int i=1;i<=n;i++)printf("%d",t[i].tot),putchar(' ');
	return 0;
}