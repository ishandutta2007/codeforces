#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,Q,X[300100],Y[300100],Z[300100];
vector<int>v[300100];
priority_queue<pair<ll,int> >q;
struct SPT{
	ll dis[300100];
	bool vis[300100],spc[300100];
	int anc[300100][19],dep[300100],id[300100];
	int LCA(int x,int y){
		if(dep[x]>dep[y])swap(x,y);
		for(int i=18;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))y=anc[y][i];
		if(x==y)return x;
		for(int i=18;i>=0;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
		return anc[x][0];
	}
	void init(){
		while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x])continue;vis[x]=true;
			for(int i=1;i<=18;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
			for(auto i:v[x]){
				int y=X[i]^Y[i]^x;
				if(dis[y]>dis[x]+Z[i])
					id[y]=i,anc[y][0]=x,dep[y]=dep[x]+1,q.emplace(-(dis[y]=dis[x]+Z[i]),y);
			}
		}
		for(int i=2;i<=n;i++)spc[id[i]]=true;
	}
}t[2];
ll res[300100];
vector<ll>r[300100],s[300100];
multiset<ll>S;
template<typename T>void read(T&x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
template<typename T>void print(T x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
void Try(int i){
	int a=t[0].LCA(X[i],n),b=t[1].LCA(Y[i],1);
	if(t[0].dep[b]<t[0].dep[a])return;
	ll w=t[0].dis[X[i]]+Z[i]+t[1].dis[Y[i]];
	r[b].push_back(w);
	s[a].push_back(w);
}
vector<int>u[300100];
bool sp[300100];
int main(){
	read(n),read(m),read(Q);
	for(int i=1;i<=m;i++)
		read(X[i]),read(Y[i]),read(Z[i]),v[X[i]].push_back(i),v[Y[i]].push_back(i);
	memset(t[0].dis,0x3f,sizeof(t[0].dis)),q.emplace(-(t[0].dis[1]=0),1);
	t[0].init();
//	printf("%lld\n",t[0].dis[n]);
	memset(t[1].dis,0x3f,sizeof(t[1].dis));
	q.emplace(-(t[1].dis[n]=0),n);
	for(int x=n,y;x!=1;x=y){
		y=t[0].anc[x][0];
		q.emplace(-(t[1].dis[y]=t[0].dis[n]-t[0].dis[y]),y);
		t[1].id[y]=t[0].id[x],t[1].anc[y][0]=x,t[1].dep[y]=t[1].dep[x]+1;
	}
	t[1].init();
	for(int i=1,x,y;i<=Q;i++){
		read(x),read(y),u[x].push_back(i);
		if(t[0].dis[X[x]]>t[0].dis[Y[x]])swap(X[x],Y[x]);
		res[i]=t[0].dis[X[x]]+t[1].dis[Y[x]]+y;
	}
//	for(int x=n;x;x=t[0].anc[x][0])printf("%d ",x);puts("");
//	for(int x=1;x;x=t[1].anc[x][0])printf("%d ",x);puts("");
	for(int i=1;i<=m;i++)if(!t[0].spc[i])Try(i),swap(X[i],Y[i]),Try(i);
//	puts("IN");
	S.insert(0x3f3f3f3f3f3f3f3f);
//	printf("%lld\n",res);
	for(int i=n;i!=1;i=t[0].anc[i][0]){
		for(auto x:r[i])S.insert(x);
		for(auto x:s[i])S.erase(S.find(x));
		for(auto x:u[t[0].id[i]])res[x]=min(res[x],*S.begin()),sp[x]=true;
	}
	for(int i=1;i<=Q;i++,putchar('\n'))
		if(!sp[i])print(min(res[i],t[0].dis[n]));
		else print(res[i]);
	return 0;
}