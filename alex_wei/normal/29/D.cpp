#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sortv(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;

#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=305;
int n,fa[N][9],dep[N],c[N],l[N],leaf;
vector <int> e[N];
void dfs(int id,int f,int d){
	fa[id][0]=f,dep[id]=d;
	int isl=1;
	for(auto to:e[id])if(to!=f)dfs(to,id,d+1),isl=0;
	leaf+=isl;
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=8;~i;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=8;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void check(int id,int f){
	for(auto to:e[id])if(to!=f)check(to,id),c[id]+=c[to];
	if(id>1&&c[id]!=2)puts("-1"),exit(0);
}
void move(int from,int to){
	int rev=0;
	if(dep[from]<dep[to])swap(from,to),rev=1;
	vector <int> p;
	while(from!=to){
		p.pb(rev?from:fa[from][0]);
		from=fa[from][0];
	}
	if(rev)rev(p);
	for(auto it:p)cout<<it<<" ";
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	dfs(1,0,1);
	for(int i=1;i<9;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	l[0]=l[leaf+1]=1;
	for(int i=1;i<=leaf+1;i++){
		if(i<=leaf)cin>>l[i],c[l[i]]+=2;
		c[LCA(l[i-1],l[i])]-=2;
	}
	check(1,0);
	cout<<"1 ";
	for(int i=1;i<=leaf+1;i++){
		int d=LCA(l[i-1],l[i]);
		move(l[i-1],d),move(d,l[i]);
	}
    return 0;
}