#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
#define S 10000000
#define N 800
using namespace std;
int n,len,st,t,d[N+5<<1],nows[N+5<<1],fl[N+5<<1],ans,now,un,wn;bitset<N+5> dis[N+5];
char c[S+5];vector<int> pl[N+5];queue<int> q;
struct AC{
	int son[S+5][2],fail[S+5],val[S+5],cnt,now,i,pus;
	I void insert(int id){for(i=1,now=0;i<=len;i++) !son[now][c[i]-'a']&&(son[now][c[i]-'a']=++cnt),now=son[now][c[i]-'a'],pl[id].push_back(now);val[now]=id;}
	I void make(){
		for(i=0;i<=1;i++) son[0][i]&&(q.push(son[0][i]),0);val[0]=-1;
		while(!q.empty()){
			now=q.front();q.pop();!val[now]&&(val[now]=val[fail[now]]);
			for(i=0;i<=1;i++)!son[now][i]?(son[now][i]=son[fail[now]][i]):(q.push(son[now][i]),fail[son[now][i]]=son[fail[now]][i]);
		}
	}
	I void find(int id){for(i=0;i<pl[id].size();i++)now=pl[id][i],val[now]==id&&(now=fail[now]),~val[now]&&(dis[id][val[now]]=1);}
}g;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[N+5<<1];yyy f[N*N+5<<1];
	I void add(int x,int y,int z){f[head]=(yyy){y,z,h[x]};h[x]=head++;}
}s;
I void get(int x,int y,int z){s.add(x,y,z);s.add(y,x,0);/*printf("%d %d\n",x,y);*/}
I int bfs(){
	memset(d,0x3f,sizeof(d));memset(nows,-1,sizeof(nows));while(!q.empty()) q.pop();q.push(st);d[st]=0;nows[st]=s.h[st];
	while(!q.empty()){
		now=q.front();q.pop();
		for(int i=s.h[now];~i;i=tmp.z){
			tmp=s.f[i];if(tmp.w&&d[tmp.to]>=1e9){
				d[tmp.to]=d[now]+1;nows[tmp.to]=s.h[tmp.to];q.push(tmp.to);
				if(tmp.to==t) return 1;
			} 
		}
	}
	return 0;
}
I int dfs(int x,int sum){
	if(x==t) return sum;yyy tmp;int k,pus=0;
	for(int i=s.h[x];~i;i=tmp.z){
		tmp=s.f[i];
		if(tmp.w&&d[tmp.to]==d[x]+1){
			k=dfs(tmp.to,min(tmp.w,sum));if(!k) d[tmp.to]=1e9;
			pus+=k;sum-=k;s.f[i].w-=k;s.f[i^1].w+=k;
		}
		if(!sum) break;
	}
	return pus;
}
I void check(int x){
	if(fl[x]||x==t||x==st) return;fl[x]=1;yyy tmp;
	for(int i=s.h[x];~i;i=tmp.z)  tmp=s.f[i],!tmp.w&&(check(tmp.to),0);
} 
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	re int i,j,k;scanf("%d",&n);st=0;t=2*n+1;memset(s.h,-1,sizeof(s.h));
	for(i=1;i<=n;i++) scanf("%s",c+1),len=strlen(c+1),g.insert(i);
	g.make();for(i=1;i<=n;i++) g.find(i);
	for(i=1;i<=n;i++) get(0,i,1),get(i+n,t,1);
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++)dis[i][k]&&(dis[i]|=dis[k],0);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) i^j&&dis[i][j]&&(get(i,j+n,1),0);
	}
	while(bfs()) ans+=dfs(st,1e9);printf("%d\n",n-ans);
	for(i=s.h[t];~i;i=tmp.z) tmp=s.f[i],!tmp.w&&(check(tmp.to),0);
	for(i=1;i<=n;i++) if(!(fl[i]|(fl[i+n]^1))) printf("%d ",i);
}