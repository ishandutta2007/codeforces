#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const int maxn=2005;
int n,m,r,c,x,y,cnt[maxn*maxn],tot,bel[maxn][maxn];
char mp[maxn][maxn];
vector<int>G[maxn*maxn],F[maxn*maxn];
typedef pair<int,int> pii;
#define X first
#define Y second
pii dis[maxn*maxn];
int main() {
	read(n),read(m),read(r),read(c),read(x),read(y);
	for(int i=1;i<=n;++i)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mp[i][j]!='*'&&!bel[i][j]) {
				++tot;
				int p=i;
				while(p<=n&&mp[p][j]=='.')
					cnt[tot]++,bel[p][j]=tot,++p;
			}
//	for(int i=1;i<=n;++i,puts(""))
//		for(int j=1;j<=m;++j)
//			cout<<bel[i][j]<<" ";
	for(int i=1;i<=tot;++i)
		dis[i]=pii(1e9+7,1e9+7);
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			if(bel[i][j]&&bel[i][j+1]&&(bel[i-1][j]!=bel[i][j]||bel[i-1][j+1]!=bel[i][j+1]))
				G[bel[i][j]].push_back(bel[i][j+1]),F[bel[i][j+1]].push_back(bel[i][j]);
	queue<int>q;
	q.push(bel[r][c]);
	dis[bel[r][c]]=pii(0,0);
	for(int u;!q.empty();q.pop()) {
		u=q.front();
		if(dis[u].X>x||dis[u].Y>y)
			continue;
		for(int i=0;i<(int)G[u].size();++i) {
			int v=G[u][i];
			if(dis[v].Y>dis[u].Y+1)
				dis[v].Y=dis[u].Y+1,dis[v].X=dis[u].X,q.push(v);
		}
		for(int i=0;i<(int)F[u].size();++i) {
			int v=F[u][i];
			if(dis[v].X>dis[u].X+1)
				dis[v].X=dis[u].X+1,dis[v].Y=dis[u].Y,q.push(v);
		}
	}
//	for(int i=1;i<=tot;++i)
//		cout<<dis[i].X<<" "<<dis[i].Y<<endl;
	int ans=0;
	for(int i=1;i<=tot;++i)
		if(dis[i].X<=x&&dis[i].Y<=y)
			ans+=cnt[i];
	cout<<ans;
}