#include<bits/stdc++.h>
#define N 500000
#define int long long
#define gc() getchar()
using namespace std;
int n,p[2*N+1],dp[2001][2001],gp[2001][2001],g[2*N+1];
int fl[2*N+1],na[2*N+1],b[4*N+1],nxt[4*N+1],ls[2*N+1],pb,bq[4*N+1];
pair<int,int>a[N+1];
void lb(int np,int nq,int nr){/*cout<<np<<' '<<nq<<' '<<nr<<endl;*/ls[np]=(na[np]?nxt[ls[np]]:na[np])=++pb,b[pb]=nq,bq[pb]=nr;}
int qread(){int nans=0;char c=gc();while(c<'0'||c>'9')c=gc();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=gc();return nans;}
void putin(){
	cin>>n;
	if(n%2==0){
		cout<<"First\n";
		for(int i=1;i<=2*n;i++){
			if(i<=n)cout<<i<<' ';else cout<<i-n<<' ';
		}
		cout<<'\n';return;
	}
	cout<<"Second\n";
	cout.flush();
	for(int i=1;i<=2*n;i++){
		cin>>p[i];
		if(a[p[i]].first)a[p[i]].second=i;
		else a[p[i]].first=i;
	}
}
void cal0(){
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2*n;j++){
			if(dp[i-1][j]){
				dp[i][(j+a[i].first)%(2*n)]=1;
				dp[i][(j+a[i].second)%(2*n)]=1;
				gp[i][(j+a[i].first)%(2*n)]=a[i].first;
				gp[i][(j+a[i].second)%(2*n)]=a[i].second;
			}
		}
	}
	int np=0;
	for(int i=n;i>=1;i--){
		cout<<gp[i][np]<<' ';
		np=(np-gp[i][np]+2*n)%(2*n);
	}cout<<'\n';
}
void ycl(){
	for(int i=1;i<=2*n;i++){
		lb((i-1)%n+1,p[i]+n,i);
		lb(p[i]+n,(i-1)%n+1,i);
	}
}
void dfs(int x,int nt){
	fl[x]=1;
	for(int i=na[x];i;i=nxt[i]){
		if(!fl[b[i]]){
			if(nt)g[bq[i]]=1;
			dfs(b[i],nt^1);
		}
	}
}
void cal1(){
	ycl();
	for(int i=1;i<=2*n;i++){
		if(!fl[i]){
			dfs(i,1);
		}
	}
	int ns=0;
	for(int i=1;i<=2*n;i++){
		if(g[i])ns+=i;
	}
	int aa=0,bb=0;
	if(ns%(2*n)==0){
		for(int i=1;i<=2*n;i++)if(g[i])aa++,bb+=i,cout<<i<<' ';cout<<endl;
	}else{
		for(int i=1;i<=2*n;i++)if(!g[i])aa++,bb+=i,cout<<i<<' ';cout<<endl;
	}
//	cerr<<aa<<' '<<bb<<endl;
}
signed main(){
//	freopen("pair1.in","r",stdin);
//	freopen("pair.out","w",stdout);
	putin();
	if(n%2==0)return 0;
	cal1();
	return 0;
}