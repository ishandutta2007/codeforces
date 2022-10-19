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
int n,K,c[10],m,q,lim,sta[130],id[1<<10];
typedef long long ll;
void chmn(ll&x,ll y){if(x>y)x=y;}
struct Matrix{
ll a[130][130];
Matrix(){memset(a,0x3f,sizeof(a));}
ll*operator[](const int&x){return a[x];}
friend Matrix operator*(const Matrix&u,const Matrix&v){
	Matrix w;
	for(int i=0;i<lim;i++)for(int j=0;j<lim;j++)for(int k=0;k<lim;k++)chmn(w.a[i][j],u.a[i][k]+v.a[k][j]);
	return w;
}
void print()const{for(int i=0;i<lim;i++,puts(""))for(int j=0;j<lim;j++)printf("%lld ",a[i][j]);}
}mat[30];
ll f[130],g[130];
map<int,ll>mp;
int p[30],pos=1;
void consider(const Matrix&v){
	for(int i=0;i<lim;i++)for(int j=0;j<lim;j++)chmn(g[j],f[i]+v.a[i][j]);
	for(int i=0;i<lim;i++)f[i]=g[i],g[i]=0x3f3f3f3f3f3f3f3f;
}
void trans(int len){
	len=max(len,0);
	for(int i=29;i>=0;i--)if(len&(1<<i))consider(mat[i]);
	pos+=len;
	// printf("tlen%d:",pos);for(int i=0;i<lim;i++)printf("%d ",f[i]);puts("");
}
void trans(){
	for(int i=0;i<lim;i++){
		if(!(sta[i]&1)){chmn(g[id[sta[i]>>1]],f[i]);continue;}
		for(int j=1;j<=K;j++)if(!(sta[i]&(1<<j)))
			chmn(g[id[(sta[i]|(1<<j))>>1]],f[i]+c[j]+mp[pos+j]);
	}
	for(int i=0;i<lim;i++)f[i]=g[i],g[i]=0x3f3f3f3f3f3f3f3f;
	pos++;
	// printf("tsin%d:",pos);for(int i=0;i<lim;i++)printf("%d ",f[i]);puts("");
}
int main(){
	scanf("%d%d%d%d",&n,&K,&m,&q);
	for(int i=1;i<=K;i++)scanf("%d",&c[i]);
	memset(id,-1,sizeof(id));
	for(int i=0;i<(1<<K);i++)if(__builtin_popcount(i)==n)sta[lim]=i,id[i]=lim,lim++;
	// for(int i=0;i<lim;i++)printf("%d:%d\n",i,sta[i]);
	for(int i=0;i<lim;i++){
		if(!(sta[i]&1)){mat[0][i][id[sta[i]>>1]]=0;continue;}
		for(int j=1;j<=K;j++)if(!(sta[i]&(1<<j)))
			// printf("%d,%d(%d=%d)\n",i,j,(sta[i]|(1<<j))>>1,id[(sta[i]|(1<<j))>>1]),
			mat[0][i][id[(sta[i]|(1<<j))>>1]]=c[j];
	}
	// mat[0].print();
	for(int i=1;i<30;i++)mat[i]=mat[i-1]*mat[i-1];
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),p[i]=x,mp[x]+=y;
	sort(p+1,p+q+1);
	memset(f,0x3f,sizeof(f)),memset(g,0x3f,sizeof(g)),f[0]=0;
	for(int i=1;i<=q;i++){
		trans(max(0,p[i]-K-pos));
		while(pos<=p[i]&&pos<=m-n)trans();
	}
	trans(m-n-pos+1);
	printf("%lld\n",f[0]);
	return 0;
}