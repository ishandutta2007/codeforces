#include<bits/stdc++.h>
using namespace std;
#define y1 _19260817
#define y2 _17680321
int n,m,a[400100],stk[400100],res[400100],tp;
struct Query{
	int x1,x2,y1,y2,id;
	Query(int i){scanf("%d%d%d%d",&x1,&y1,&x2,&y2),id=i;}
	friend bool operator <(const Query &x,const Query &y){return x.x2<y.x2;}
};
#define lson t[x].ch[0]
#define rson t[x].ch[1]
int cnt,rt;
struct Treap{
	int ch[2],sz,val,pos,mnp,mnm,rd;
}t[400100];
void pushup(int x){
	t[x].mnp=t[x].val-2*t[x].pos;
	t[x].mnm=-t[x].val-2*t[x].pos;
	t[x].sz=1;
	if(lson)t[x].mnp=min(t[x].mnp,t[lson].mnp),t[x].mnm=min(t[x].mnm,t[lson].mnm),t[x].sz+=t[lson].sz;
	if(rson)t[x].mnp=min(t[x].mnp,t[rson].mnp),t[x].mnm=min(t[x].mnm,t[rson].mnm),t[x].sz+=t[rson].sz;
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd){t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void splitbypos(int x,int k,int &u,int &v){//u:<k.
	if(!x){u=v=0;return;}
	if(t[x].pos<k)u=x,splitbypos(rson,k,rson,v);
	else v=x,splitbypos(lson,k,u,lson);
	pushup(x);
}
void splitbyval(int x,int k,int &u,int &v){//u:<k.
	if(!x){u=v=0;return;}
	if(t[x].val<k)u=x,splitbyval(rson,k,rson,v);
	else v=x,splitbyval(lson,k,u,lson);
	pushup(x);
}
void splitbysize(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	if(t[lson].sz>=k)v=x,splitbysize(lson,k,u,lson);
	else u=x,splitbysize(rson,k-t[lson].sz-1,rson,v);
	pushup(x);
}
int newnode(int x){
	int u=++cnt;
	t[u].ch[0]=t[u].ch[1]=0;
	t[u].pos=x,t[u].val=a[x];
	t[u].rd=rand()*rand();
	pushup(u);
	return u;
}
void Insert(int x){
	int a,b;
	splitbypos(rt,x,a,b);
	rt=merge(merge(a,newnode(x)),b);
}
void Delete(int x){
	int a,b,c;
	splitbypos(rt,x,a,b);
	splitbysize(b,1,b,c);
	rt=merge(a,c);
}
int Ask(int bef,int x,int now){
	int a,b,c,e,f;
	splitbysize(rt,bef-1,b,c);
	splitbyval(b,x,a,b);
	int ret=0x3f3f3f3f;
	splitbyval(a,now+1,e,f);
	ret=min(ret,min(t[e].mnm+x,t[f].mnm+x+1));
	a=merge(e,f);
	
	splitbyval(b,now+1,e,f);
	ret=min(ret,min(t[e].mnp-x,t[f].mnp-x+1));
	b=merge(e,f);
	
	rt=merge(merge(a,b),c);
	return ret;
}
void Iterate(int x){
	if(!x)return;
	Iterate(lson);
	printf("[%d:%d]",x,a[x]);
	Iterate(rson);
}
void func(vector<Query>&v){
	sort(v.begin(),v.end());
	tp=0;
	cnt=rt=0;
	for(int i=0,j=1;i<v.size();i++){
//		printf("[%d,%d]\n",v[i].x1,v[i].x2);
		while(j<=v[i].x2){
			while(tp&&a[stk[tp]]>a[j])Delete(stk[tp--]);
			Insert(stk[++tp]=j++);
		}
//		for(int k=1;k<=tp;k++)printf("%d ",stk[k]);puts("");
//		for(int k=1;k<=tp;k++)printf("%d ",a[stk[k]]);puts("");
		int tmp=lower_bound(stk+1,stk+tp+1,v[i].x1)-stk;
		int fin=min(v[i].y1,a[stk[tmp]]);
//		printf("%d,%d\n",tmp,fin);
		res[v[i].id]=min(res[v[i].id],abs(v[i].x1-v[i].x2)+abs(fin-v[i].y2));//do not press anything special
		
		res[v[i].id]=min(res[v[i].id],abs(v[i].x1-v[i].x2)+v[i].y2+1);//press a HOME somewhere.
		
		a[n+1]=v[i].y2;
		int pmt=lower_bound(stk+tmp,stk+tp+1,n+1,[](int u,int v){return a[u]<a[v];})-stk;
		res[v[i].id]=min(res[v[i].id],abs(v[i].x1-v[i].x2)+abs(a[stk[pmt]]-v[i].y2)+1);//press an END somewhere in [x1,y1]
		if(pmt>tmp)res[v[i].id]=min(res[v[i].id],abs(v[i].x1-v[i].x2)+abs(a[stk[pmt-1]]-v[i].y2)+1);
		
		res[v[i].id]=min(res[v[i].id],v[i].x2+v[i].x1+Ask(tmp,v[i].y2,v[i].y1));//move to somewhere in [1,x1), and press an END if need.
		
		v[i].y1=fin;//stock fin for later use.
	}
	tp=0;
	cnt=rt=0;
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)v[i].x1=n-v[i].x1+1,v[i].x2=n-v[i].x2+1;
	reverse(a+1,a+n+1);
	for(int i=0,j=1;i<v.size();i++){
		while(j<=v[i].x2){
			while(tp&&a[stk[tp]]>a[j])Delete(stk[tp--]);
			Insert(stk[++tp]=j++);
		}
//		Iterate(rt);puts("");
//		printf("%d %d\n",v[i].y2,v[i].y1);
		res[v[i].id]=min(res[v[i].id],abs(v[i].x1-v[i].x2)+2*v[i].x2+Ask(tp+1,v[i].y2,v[i].y1));//move to somewhere in (x2,n], press an END if need.
	}
	reverse(a+1,a+n+1);
}
vector<Query>v1,v2;
int main(){
	scanf("%d",&n),memset(res,0x3f,sizeof(res)),t[0].mnm=t[0].mnp=0x3f3f3f3f;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		Query q(i);
		if(q.x1<=q.x2)v1.push_back(q);
		else q.x1=n-q.x1+1,q.x2=n-q.x2+1,v2.push_back(q);
	}
	func(v1);
	reverse(a+1,a+n+1);
	func(v2);
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}
/*
13
245468 180916 290696 340113 166951 259500 135270 32481 211977 128410 185376 380953 27639
1
1 244718 8 27128
*/