#include <bits/stdc++.h>
using namespace std;
const int maxn=500010;
typedef long long ll;

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}

struct edge{
	int x,c;
	edge(int a=0,int b=0){
		x=a,c=b;
	}
};

vector<edge> to[maxn];
vector<int> active[maxn];

multiset<ll> q[maxn];
multiset<ll>::iterator it;

ll sum[maxn],d[maxn][2],ans;
int lim,pos[maxn],val[maxn],n;

bool cmp(edge a,edge b){
	return to[a.x].size()<to[b.x].size();
}

void dfs(int u,int f){
	val[u]=lim;
	while(pos[u]<to[u].size()&&to[to[u][pos[u]].x].size()<=lim){
		sum[u]+=to[u][pos[u]].c;
		q[u].insert(to[u][pos[u]].c);
		pos[u]++;
	} 
	while(q[u].size()>to[u].size()-lim){
		it=q[u].end();it--;
		sum[u]-=*it;
		q[u].erase(it);
	}
	ll res=0;
	for (int i=pos[u];i<to[u].size();++i){
		int v=to[u][i].x;
		if (v==f) continue;
		dfs(v,u);
		sum[u]+=d[v][1]-d[v][0]+to[u][i].c;
		res+=d[v][0];
		q[u].insert(d[v][1]-d[v][0]+to[u][i].c);
	}
	int nr=q[u].size();
	it=q[u].end();it--;
	while(nr>to[u].size()-lim){
		if (*it<=0) break;
		res-=*it;it--;nr--;
	}
	d[u][0]=sum[u]+res;
	d[u][1]=sum[u]+res-max(0ll,*it);
	for (int i=pos[u];i<to[u].size();++i){
		int v=to[u][i].x;
		if (v==f) continue;
		sum[u]-=d[v][1]-d[v][0]+to[u][i].c;
		it=q[u].find(d[v][1]-d[v][0]+to[u][i].c);
		q[u].erase(it);
	}
}

int main(){
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  int qr = read();
  while (qr--) {
    n=read();
    int k = read();
    lim = 0;
    for (int i = 0; i <= n; i++) {
      pos[i] = 0;
      val[i] = 0;
      to[i].clear();
      active[i].clear();
      q[i].clear();
      sum[i] = 0;
      for (int t = 0; t < 2; t++) {
        d[i][t] = 0;
      }
    }
    ans = 0;
    ll orz = 0;
    for (int i=1;i<n;++i){
      int u=read(),v=read(),w=read();
      to[u].push_back(edge(v,w));
      to[v].push_back(edge(u,w));
      orz += w;
      ans+=w;
    }
    vector <ll> ret(n);
    ret[0] = ans;
    for (int i=1;i<=n;++i){
      sort(to[i].begin(),to[i].end(),cmp);
      for (int j=1;j<to[i].size();++j) active[j].push_back(i);
    }
    for (int i=1;i<n;++i){
      lim=i;ans=0;
      for (auto v:active[i])
      if (val[v]<i) dfs(v,0),ans+=d[v][0];
      ret[i] = ans;
    }
    k = min(k, n - 1);
    cout << orz - ret[k] << '\n';
  }
}