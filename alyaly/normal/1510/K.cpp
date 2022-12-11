#include<bits/stdc++.h>
#define re register int 
#define ll long long
#define LL inline ll
#define V inline void
#define I inline int
#define FOR(i,a,b) for(re i=(a),i##i=(b);i<=i##i;++i)
#define ROF(i,a,b) for(re i=(a),i##i=(b);i>=i##i;--i)
#define gc getchar()
//#define gc (ft==fs&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin),ft==fs))?0:*fs++
using namespace std;
char *fs,*ft,buf[1<<18];
const int N=4100;
LL read(){
	ll p=0,w=0; char ch=gc;
	while(!isdigit(ch)) w=ch=='-',ch=gc;
	while(isdigit(ch)) p=p*10+ch-'0',ch=gc;
	return w?-p:p;
}
int n,m,a[N],ans,b[2*N],d[2*N];
V ipt(){ n=read(); FOR(i,1,2*n) a[i]=read();}
V opt(){
	FOR(i,1,2*n) d[i]=i;
	FOR(k,1,ans){
		if(b[k]) {
			FOR(i,1,n) swap(d[i],d[n+i]);
		}
		else {
			FOR(i,1,n) swap(d[2*i-1],d[2*i]);
		}
	}
	FOR(i,1,2*n) if(a[i]!=d[i]) ans=-1;
	cout<<ans;	
}
int c[N],cnt;
I ck(){
	FOR(i,1,2*n) d[i]=i;
	FOR(k,1,cnt){
		if(c[k]){
			FOR(i,1,n) swap(d[i],d[n+i]);
		}
		else{
			FOR(i,1,n) swap(d[2*i-1],d[2*i]);
		}
	}
	FOR(i,1,2*n) if(d[i]!=a[i]) return 0;
	return 1;
}
V dfs(int u,int tp){
	if(u==m){
		if(cnt<ans&&ck()){
			ans=cnt;
			FOR(i,1,ans) b[i]=c[i];
		}
		return ;
	}
	int v=0;
	c[++cnt]=tp;
	if(tp){
		if(u>n) v=u-n;
		else v=u+n;
	}
	else {
		if(u&1) v=u+1;
		else v=u-1;
	}
	dfs(v,tp^1);
	return ;
}
V sol1(){
	FOR(i,1,2*n) if(a[i]==1) m=i;
	ans=n*n;
	cnt=0,dfs(1,1);
	cnt=0,dfs(1,0);
	if(ans==n*n) ans=-1;
	return ;
}
V sol2(){
	FOR(i,1,2*n) if(a[i]==1) m=i;
	if(m==2) b[++ans]=0; 
	else if(m==n+1) b[++ans]=1;
	else if(m==n+2) b[++ans]=0,b[++ans]=1;
	return ;
}
int main(){
	ipt();
	if(n&1) sol1();
	else sol2();
	opt();
	return 0;
}