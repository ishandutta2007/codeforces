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
typedef long double ldb;
typedef unsigned long long ull;
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int> 
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
	template <class I>
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1005;
int T,n,m,vs[N][N],a[N][N],id;
char s[N][N];
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
il void dfs(ct x,ct y){
	if(x<1||y<1||x>n||y>m||vs[x][y]||a[x][y]) return;
	vs[x][y]=1;
	for(it k=0,tx,ty;k<4;++k){
		tx=x+dx[k],ty=y+dy[k];
		if(s[tx][ty]!='#') dfs(tx,ty);
	}
}
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d%d",&n,&m);it fl=1;
		for(i=1;i<=n;++i) scanf("%s",s[i]+1);
		for(i=n+1;~i;--i) for(j=m+1;~j;--j) a[i][j]=vs[i][j]=0;
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(s[i][j]=='B')
					for(it k=0,tx,ty;k<4;++k){
						tx=i+dx[k],ty=j+dy[k];
						if(tx<1||tx>n||ty<1||ty>m) continue;
						a[tx][ty]=1;
					}
		if(s[n][m]=='B'){puts("No");continue;}
		dfs(n,m);
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(s[i][j]=='G'&&(!vs[i][j])){fl=0;break;}
		fl?puts("Yes"):puts("No");
	}
	return 0;
}