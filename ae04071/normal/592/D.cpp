#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;

int n,m,c[200001];
vector<int> adj[200001];

int preproc(int cur,int p) {
	int f=0;
	vector<int> res;
	for(auto &it:adj[cur]) if(it!=p) {
		int v=preproc(it,cur);
		if(v) res.push_back(it);
		f|=v;
	}
	if(p) res.push_back(p);
	adj[cur]=res;
	return f|c[cur];
}
pii f1(int cur,int p) {
	pii ans(0,cur);
	for(auto &it:adj[cur]) if(it!=p) {
		pii v = f1(it,cur);
		v.fi++;
		if(ans.fi < v.fi || (ans.fi==v.fi && ans.se > v.se)) {
			ans = v;
		}
	}
	return ans;
}
pii f2(int cur,int p) {
	pii ans(0,cur);
	for(auto &it:adj[cur]) if(it!=p) {
		pii v = f2(it,cur);
		v.fi++;
		if(ans.fi < v.fi || (ans.fi==v.fi && ans.se > v.se)) {
			ans = v;
		}
	}
	return ans;
}
int cal(int cur,int p) {
	int sum=0;
	for(auto &it:adj[cur]) if(it!=p) {
		sum += cal(it,cur);
	}
	return sum+2;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0,v;i<m;i++) {
		scanf("%d",&v);
		c[v]=1;
	}
	int r=1;
	for(int i=1;i<=n;i++) if(c[i]) {
		r=i;
		break;
	}
	if(m==1) {
		printf("%d\n%d\n",r,0);
		return 0;
	}
	preproc(r,0);

	pii res = f2(r=f1(r,0).se,0);
	printf("%d\n%d\n",min(res.se,r),cal(r,0) - res.fi - 2);
	
	
	return 0;
}