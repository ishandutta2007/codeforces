//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = 3001;
const int M = 5001;
VI g[N],rg[N];
int d[2][N][N],far[2][4][N],vis[N],q[N],st,en,len;
II temp[N];
pair<int,VI> ans;
void bfs(VI g[],int s,int d[]){
	st=en=0;q[en++]=s;SET(vis,0);vis[s]=1;d[s]=0;
	while(st<en){
		int u = q[st++];
		for(auto w : g[u])
			if(!vis[w]){
				d[w]=d[u]+1;
				vis[w]=1;
				q[en++]=w;
			}
	}
}
void process(int n,int m){
	for(int i=0;i<=1;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				d[i][j][k]=-int(1e6);
	for(int i=1;i<=n;i++)
		bfs(g,i,d[0][i]),bfs(rg,i,d[1][i]);
	for(int i=0;i<=1;i++)
		for(int j=1;j<=n;j++){
			len=0;
			for(int k=1;k<=n;k++)
				if(d[i][j][k] >= 0)
					temp[len++] = {d[i][j][k],k};
			sort(temp,temp+len);reverse(temp,temp+len);
			for(int k=0;k<min(4,len);k++)
				far[i][k][j]=temp[k].S;
		}
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=1;i<=m;i++){
		int u,v;
		si(u);si(v);
		g[u].PB(v);
		rg[v].PB(u);
	}
	process(n,m);
	for(int b=1;b<=n;b++)
		for(int c=1;c<=n;c++){
			if(b==c)continue;
			for(int i=0;i<4;i++){
				int a = far[1][i][b];
				if(a == b)break;
				if(a == b || a == c)continue;
				for(int j=0;j<4;j++){
					int d = far[0][j][c];
					if(d == c)break;
					if(d == a || d == b)continue;
					int cans = ::d[0][a][b] + ::d[0][b][c] + ::d[0][c][d];
					if(cans>ans.F)
						ans = {cans,{a,b,c,d}};
					break;
				}
			}
		}
	//trace(ans.F);
	for(int i=0;i<4;i++)
		printf("%d ",ans.S[i]);
	puts("");
	return 0;
}