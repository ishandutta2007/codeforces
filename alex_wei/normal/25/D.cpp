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

const int N=1e3+5;
int n,a,b,c,d,vis[N];
vector <int> e[N],ind;
vector <pii> a1,a2;
void dfs(int id,int f,int fm){
	vis[id]=fm;
	for(auto it:e[id]){
		if(it!=f){
			if(vis[it]&&!a)a=id,b=it;
			if(!vis[it])dfs(it,id,fm);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		a=b=c=d=0;
		ind.clear();
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++)if(!vis[j]){
			ind.push_back(j);
			dfs(j,0,j);
		}
		if(!a){
			cout<<a1.size()<<endl;
			for(int i=0;i<a1.size();i++)
				cout<<a1[i].fi<<" "<<a1[i].se<<" "<<a2[i].fi<<" "<<a2[i].se<<endl;
			exit(0);
		}
		c=vis[a];
		for(auto it:ind)if(it!=c)d=it;
		a1.push_back({a,b}),a2.push_back({c,d});
		e[c].push_back(d);
		e[d].push_back(c);
		for(int i=0;i<e[a].size();i++)
			if(e[a][i]==b){
				e[a].erase(e[a].begin()+i);
				break;
			}
		for(int i=0;i<e[b].size();i++){
			if(e[b][i]==a){
				e[b].erase(e[b].begin()+i);
				break;
			}
		}
	}
    return 0;
}