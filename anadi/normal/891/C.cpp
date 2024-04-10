#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5e5 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;

int n, m;
int rep[N];
int roz[N];
bool ans[N];

int q;
int last[N];
stack <PII> S;

vector <int> W[N];
vector <int> req[N];
vector <int> quest[N];
pair <PII, int> edge[N];

inline bool cmp(int u, int v){
	if(edge[u].nd == edge[v].nd)
		return u < v;
	return edge[u].nd < edge[v].nd;
}

int Find(int u){
	if(rep[u] == u)
		return u;
	return Find(rep[u]);
}

bool Union(int u, int v){
	int fu = Find(u), fv = Find(v);
	if(fu == fv)	return false;
	
	if(roz[fu] < roz[fv])
		swap(fu, fv);
	
	rep[fv] = fu;
	roz[fu] += roz[fv];

	S.push({fu, fv});
	return true;
}

void remove(int u, int v){
	rep[v] = v;
	roz[u] -= roz[v];
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		edge[i] = {{u, v}, c};
		W[c].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i){
		rep[i] = i; roz[i] = 1;
	}
	
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		int a;
		scanf("%d", &a);
		while(a--){
			int t; scanf("%d", &t);
			quest[i].push_back(t);
		}
		
		ans[i] = true;
		sort(quest[i].begin(), quest[i].end(), cmp);
		for(int j = 1; j < quest[i].size(); ++j)
			if(edge[quest[i][j]].nd != edge[quest[i][j - 1]].nd)
				req[edge[quest[i][j]].nd].pb(i);
		req[edge[quest[i][0]].nd].pb(i);
	}
	
	for(int i = 1; i < N; ++i){
		if(W[i].size() == 0)	continue;
		for(int t: req[i]){
			while(last[t] < quest[t].size() && edge[quest[t][last[t]]].nd == i){
				if(!Union(edge[quest[t][last[t]]].st.st, edge[quest[t][last[t]]].st.nd)){
					ans[t] = false;
					break;
				}

				++last[t];
			}
			
			while(!S.empty()){
				remove(S.top().st, S.top().nd);
				S.pop();
			}
		}
		
		for(int v: W[i])
			Union(edge[v].st.st, edge[v].st.nd);
		while(!S.empty())
			S.pop();
	}
	
	for(int i = 1; i <= q; ++i)
		if(ans[i])
			puts("YES");
		else
			puts("NO");
	return 0;
}