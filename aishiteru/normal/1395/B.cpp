#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
const int N=105; 
bool vs[N][N];
int o1[N],o2[N],n,m,nm,x,y;
il void dfs(ct x,ct y,it num){
	if(x>n||y>m||x<1||y<1||vs[x][y]) return;
	//printf("%d %d %d\n",x,y,num);
	if(num==nm){
		for(it i=1;i<=num;++i) printf("%d %d\n",o1[i],o2[i]);
		exit(0);
	}
	vs[x][y]=1,++num;
	o1[num]=x+1,o2[num]=y,dfs(x+1,y,num),
	o1[num]=x,o2[num]=y+1,dfs(x,y+1,num),
	o1[num]=x-1,o2[num]=y,dfs(x-1,y,num),
	o1[num]=x,o2[num]=y-1,dfs(x,y-1,num);
	vs[x][y]=0,--num;
}
int main(){ 
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(it i=1,j;i<=n;++i,x=(x<n?x+1:1))
		for(j=m;j--;y=j?y<m?y+1:1:y)
			printf("%d %d\n",x,y);
	return 0;
}