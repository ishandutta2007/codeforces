#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int V = 30e6;
const int N = 1e5 + 7;

const int B = 16;
const int T = 1 << 17;

int cnt;
int sz[V];
int ch[V][2];

int n, m;
int roz[N];
set <PII> S;

void add(int u, int v, int c){
	sz[u] += c;
	for(int i = B; i >= 0; --i){
		int nxt = (v & (1 << i)) ? 1 : 0;
		if(ch[u][nxt] == 0)
			ch[u][nxt] = ++cnt;

		u = ch[u][nxt];
		sz[u] += c;
	}
}

int find(int u, int v){
	int ret = 0;
	for(int i = B; i >= 0; --i){
		int nxt = 0;
		if(sz[ch[u][0]] >= sz[ch[v][0]])
			nxt = 1;
		
		if(nxt == 1)
			ret += 1 << i;
		
		u = ch[u][nxt];
		v = ch[v][nxt];
	}
	
	return ret;
}

void change(int u, int v){
	S.erase({roz[u], u});
	roz[u] += v;
	S.insert({roz[u], u});
}

int main(){
	scanf("%d %d", &n, &m); 
	cnt = n;
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &roz[i]);
		for(int j = 0; j < roz[i]; ++j){
			int x;
			scanf("%d", &x);
			add(i, x, 1);
		}
		
		S.insert({roz[i], i});
	}
	
	vector <pair <PII, int> > res;
	while(true){
		int u = (*S.begin()).nd;
		int v = (*S.rbegin()).nd;

		if(roz[v] - roz[u] <= 1)
			break;
		
		int t = find(u, v);
		res.push_back({{v, u}, t});
		
		add(u, t, 1);
		add(v, t, -1);
		
		change(u, 1);
		change(v, -1);
	}
	
	printf("%d\n", res.size());
	for(auto v: res)
		printf("%d %d %d\n", v.st.st, v.st.nd, v.nd);
	return 0;
}