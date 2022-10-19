#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define debug
#define mid ((ini+fim)/2)
#define ll long long
#define pii pair<int,int>
using namespace std;

int a[maxn];
int b[maxn];

int dg[maxn];

int f[maxn];

int pai[maxn];
int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}
void merge(int a,int b){
	pai[a] = b;
}

vector<int> are[maxn];

multiset<int> adj[maxn];

vector<int> build;

void euler(int vx){

	if(adj[vx].size() == 0){
		build.pb(vx);
		return;
	}

	while(adj[vx].size()){
		int to = *adj[vx].begin();
		adj[vx].erase(adj[vx].begin());
		euler(to);
	}

	build.pb(vx);

}

main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);

		for(int i=1;i<=n;i++) pai[i] = i;

		for(int i=0;i<n;i++)
			scanf("%d",a+i);

		for(int i=0;i<n;i++){
			scanf("%d",b+i);
			merge(find(b[i]),find(a[i]));
			adj[b[i]].insert(a[i]);
			f[b[i]]++;
		}

		int mx = 1;
		for(int i=1;i<=n;i++)
			if(f[i] > f[mx]) mx = i;

		int ok = 1;

		for(int i=1;i<=n;i++)
			if(f[i] > 0 && find(i) != find(mx)) ok = 0;

		euler(mx);

		for(int i : build) debug("%d ",i); debug("\n");

		for(int i=0;i<build.size()-1;i++){
			if(build[i] == mx || build[i+1] == mx) continue;
			are[build[i]].pb(build[i+1]);
			dg[build[i+1]]++;
		}

		queue<int> Q;
		for(int i=1;i<=n;i++){
			if(dg[i] == 0){
				Q.push(i);
			}
		}

		int mrk = 0;
		while(Q.size()){
			int u = Q.front();
			mrk++;
			Q.pop();
			for(int i : are[u]){
				dg[i]--;
				if(dg[i] == 0) Q.push(i);
			}
		}
				
		if(mrk < n) ok = 0;

		if(ok) printf("AC\n");
		else printf("WA\n");

		for(int i=0;i<=n;i++){
			f[i] = 0;
			dg[i] = 0;
			adj[i].clear();
			build.clear();
			are[i].clear();
		}

	}

}