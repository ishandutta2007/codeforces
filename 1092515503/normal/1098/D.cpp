/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,rt,cnt;
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct Treap{int ch[2],rd,sz,val;ll sum;}t[500100];
void pushup(int x){t[x].sz=t[lson].sz+t[rson].sz+1;t[x].sum=t[lson].sum+t[rson].sum+t[x].val;}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd)return t[x].ch[1]=merge(t[x].ch[1],y),pushup(x),x;
	else return t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y),y;
}
void splitbyval(int x,int k,int&u,int&v){
	if(!x)return u=v=0,void();
	if(t[x].val<=k)u=x,splitbyval(rson,k,rson,v);
	else v=x,splitbyval(lson,k,u,lson);
	pushup(x);
}
void splitbysz(int x,int k,int&u,int&v){
	if(!x)return u=v=0,void();
	if(t[lson].sz>=k)v=x,splitbysz(lson,k,u,lson);
	else u=x,splitbysz(rson,k-t[lson].sz-1,rson,v);
	pushup(x);
}
mt19937 rnd(17680321);
void insert(int val){
	int u,v;
	splitbyval(rt,val,u,v);
	int x=++cnt;t[x].val=val,t[x].sz=1,t[x].sum=val,t[x].rd=rnd()%998244353;
	rt=merge(merge(u,x),v);
}
void erase(int val){
	int u,v,w;
	splitbyval(rt,val,v,w);
	splitbysz(v,t[v].sz-1,u,v);
	rt=merge(u,w);
}
ll sum;
int res;
bool work(){
	int u,v,w;
	splitbyval(rt,sum<<1,u,v);
	// printf("%lld:%d,%d\n",sum,u,v);
	if(!v)return rt=u,false;
	splitbysz(v,1,v,w);
	if(t[v].val>(t[u].sum<<1))res--;
	sum=t[u].sum+t[v].val;
	rt=merge(u,merge(v,w));
	return true;
}
char s[10];
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%s%d",s,&x);
		if(s[0]=='+')insert(x);else erase(x);
		// puts("FUFU");
		sum=0,res=t[rt].sz;
		while(sum<=1e9&&work());
		printf("%d\n",res);
	}
	return 0;
}