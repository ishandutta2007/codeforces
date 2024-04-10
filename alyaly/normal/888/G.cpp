#include<bits/stdc++.h>
#define int long long
#define N 200000
#define D 30
#define inf 999999999999
using namespace std;
int n,a[N+1],son[D*N+1][2],sz[N+1],pb=1,ans;
vector<int>ve[D*N+1];
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
void putin(){
	n=qread();
	for(int i=1;i<=n;i++)a[i]=qread();
}
void trieadd(int u,int nx,int np){
	if(np==0){
		ve[u].push_back(nx);return;
	}
	int nt=((nx&(1ll<<(np-1)))>>(np-1));
	if(!son[u][nt])son[u][nt]=++pb;
	trieadd(son[u][nt],nx,np-1);
}
int triereq(int u,int nx,int np){
	if(!np||!u)return 0;
	int nt=((nx&(1ll<<(np-1)))>>(np-1));
	if(son[u][nt])return triereq(son[u][nt],nx,np-1);
	else return triereq(son[u][nt^1],nx,np-1)+(1ll<<(np-1));
}
void triedfs(int u,int np){
	if(son[u][0]&&son[u][1]){
		triedfs(son[u][0],np-1);
		triedfs(son[u][1],np-1);
		int nans=inf;bool nfl=0;
		if(ve[son[u][0]].size()>ve[son[u][1]].size())nfl=1,swap(son[u][0],son[u][1]);
		for(int i=0;i<ve[son[u][0]].size();i++){
			nans=min(nans,triereq(son[u][1],ve[son[u][0]][i],np-1));
		}
		ans+=nans+(1ll<<(np-1));if(nfl)swap(son[u][0],son[u][1]);
	}else if(son[u][0])triedfs(son[u][0],np-1);
	else if(son[u][1])triedfs(son[u][1],np-1);
	for(int i=0;i<ve[son[u][0]].size();i++)ve[u].push_back(ve[son[u][0]][i]);
	for(int i=0;i<ve[son[u][1]].size();i++)ve[u].push_back(ve[son[u][1]][i]);
	ve[son[u][0]].clear(),ve[son[u][1]].clear();
}
void cal0(){
	for(int i=1;i<=n;i++)trieadd(1,a[i],D);
	triedfs(1,D);
	cout<<ans<<'\n';
}
signed main(){
//	freopen("bubble1.in","r",stdin);
//	freopen("bubble.out","w",stdout);
	putin();
	cal0();
	return 0;
}
/*
7
1 4 5 6 8 9 11
*/