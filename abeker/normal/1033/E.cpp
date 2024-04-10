#include <bits/stdc++.h>
using namespace std;

const int MAXN = 605;

int N;
vector <int> adj[MAXN];
vector <int> path;
vector <int> a, b, c;

int ask(vector <int> v) {
	printf("? %d\n", v.size());
	fflush(stdout);
	for (auto it : v)
		printf("%d ", it);
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}
	
void dfs(int x, int p, int y) {
	path.push_back(x);
	if (x == y) {
		printf("N %d\n", path.size());
		fflush(stdout);
		for (auto it : path)
			printf("%d ", it);
		puts("");
		fflush(stdout);
		exit(0);
	}
	for (auto it : adj[x])
		if (it != p)
			dfs(it, x, y);
	path.pop_back();
}

void check(vector <int> v) {
	int lo = 0, hi = v.size();
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		vector <int> q;
		for (int i = 0; i <= mid; i++)
			q.push_back(v[i]);
		if (ask(q))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	if (lo == v.size())
		return;
		
	int node = v[lo];
	hi = lo;
	lo = 0;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		vector <int> q;
		for (int i = 0; i <= mid; i++)
			q.push_back(v[i]);
		vector <int> p = q;
		p.push_back(node);
		if (ask(p) > ask(q))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	dfs(node, 0, v[lo]);
}

void finish() {
	check(a);
	check(b);
}

int main() {
	scanf("%d", &N);
	
	a.push_back(1);
	for (int i = 2; i <= N; i++)
		c.push_back(i);
		
	for (int i = 1; i < N; i++) {
		int rest = ask(c);
		vector <int> tmp = a;
		for (auto it : c)
			tmp.push_back(it);
		vector <int> curr = ask(tmp) > rest ? a : b;
		
		int lo = 0, hi = curr.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			vector <int> q = c;
			for (int j = 0; j <= mid; j++)
				q.push_back(curr[j]);
			if (ask(q) > rest)
				hi = mid;
			else
				lo = mid + 1;
		}
		if (lo == curr.size())
			finish();
		
		int node = curr[lo];
		
		lo = 0, hi = c.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			vector <int> q;
			for (int j = 0; j <= mid; j++)
				q.push_back(c[j]);
			vector <int> p = q;
			p.push_back(node);
			if (ask(p) > ask(q))
				hi = mid;
			else
				lo = mid + 1;
		}
		
		if (lo == c.size() || !ask({node, c[lo]})) 
			finish();
		
		adj[node].push_back(c[lo]);
		adj[c[lo]].push_back(node);
		
		if (curr == a)
			b.push_back(c[lo]);
		else
			a.push_back(c[lo]);
		
		c.erase(c.begin() + lo);		
	}
	
	finish();
	
	printf("Y %d\n", a.size());
	fflush(stdout);
	for (auto it : a)
		printf("%d ", it);
	puts("");
	fflush(stdout);
	
	return 0;
}