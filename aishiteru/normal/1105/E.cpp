#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=105;
#define P 1000000007
int n,m,T,cn[N],some[N][N],b[N][N],none[N][N],ans,tot,g[N][N],cnt;
bool vs[N];
map<string,int> mp;
il void cal(){
	if(!tot) return;
	for(it i=1;i<=m;++i)
		for(it j=i+1;j<=m;++j)
			if(vs[i]&&vs[j]) b[i][j]=b[j][i]=0;
	for(it i=1;i<=m;++i) vs[i]=0;tot=0;
}
il void dfs(ct x,ct an,ct sn,it nn){
	if(sn+an<=ans) return;
	if(!sn&&!nn) ans=an;
	ct u=some[x][1];it v;
	for(it i=1,j;i<=sn;++i){
		v=some[x][i];
		if(b[u][v]) continue;
		for(j=1;j<=an;++j) g[x+1][j]=g[x][j];
		g[x+1][an+1]=v;it tsn=0,tnn=0;
		for(j=1;j<=sn;++j) if(b[v][some[x][j]]) some[x+1][++tsn]=some[x][j];
		for(j=1;j<=nn;++j) if(b[v][none[x][j]]) none[x+1][++tnn]=none[x][j];
		dfs(x+1,an+1,tsn,tnn),some[x][i]=0,none[x][++nn]=v;
	}
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T>>m;it op;string s;for(it i=1;i<=m;++i) for(it j=i+1;j<=m;++j) b[i][j]=b[j][i]=1;
	while(T--) cin>>op,op^1?cin>>s,!mp[s]?mp[s]=++cnt:0,tot+=(!vs[mp[s]]),++vs[mp[s]],void():cal();
	if(tot) cal();
	for(it i=1;i<=m;++i) some[1][i]=i;
	dfs(1,0,m,0),printf("%d",ans);
	return 0;
}