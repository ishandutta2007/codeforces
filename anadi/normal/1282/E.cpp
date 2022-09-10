#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n;
int in[N][3];

int deg[N];
bool was[N];

int nxt[N];
queue <int> Q;
vector <int> where[N];

void add(int u){
	for(auto v: where[u])
		if(!was[v]){
			Q.push(v);
			was[v] = true;
		}
}

void getNext(vector <int> ord){
	reverse(ord.begin(), ord.end());
	for(int j = 0; j < 3; ++j)
		nxt[in[ord[0]][j]] = in[ord[0]][(j + 1) % 3];
	
	for(int i = 1; i < (int)ord.size(); ++i){
		int cur = ord[i];
		for(int j = 0; j < 3; ++j)
			if(nxt[in[cur][j]] == 0){
				int me = in[cur][j];
				int prv = in[cur][(j + 2) % 3];
				int last = in[cur][(j + 1) % 3];
				
				if(nxt[prv] != last)
					swap(prv, last);
				assert(nxt[prv] == last);

//				printf("%d -> %d :: %d -> %d -> %d\n", prv, nxt[prv], prv, me, nxt[prv]);
				nxt[me] = nxt[prv];
				nxt[prv] = me;
				break;
			}
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i + 1 < n; ++i)
		for(int j = 0; j < 3; ++j)
			scanf("%d", &in[i][j]);
	
	for(int i = 1; i <= n; ++i){
		deg[i] = 0;
		was[i] = false;
		where[i].clear();
	}
	
	for(int i = 1; i + 1 < n; ++i)
		for(int j = 0; j < 3; ++j){
			where[in[i][j]].push_back(i);
			deg[in[i][j]]++;
		}
	
	for(int i = 1; i <= n; ++i){
		assert(deg[i] > 0);
		if(deg[i] == 1)
			add(i);
	}
	
	vector <int> qans;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		qans.push_back(u);
		for(int t = 0; t < 3; ++t){
			deg[in[u][t]]--;
			if(deg[in[u][t]] == 1)
				add(in[u][t]);
		}
	}
	
	for(int i = 1; i <= n; ++i)
		nxt[i] = 0;
	getNext(qans);
	
	int cur = 1;
	for(int i = 1; i <= n; ++i){
		printf("%d ", cur);
		cur = nxt[cur];
	}
	
	puts("");
	for(auto v: qans)
		printf("%d ", v);
	puts("");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}