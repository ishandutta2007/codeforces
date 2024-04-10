#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k;
int deg[N];
int cnt[N];

bool ask(int a, int b, int c){
	static int queries = 0;
	++queries;
	
	if(queries > 60 * n)
		return true;
	
	printf("? %d %d %d\n", a, b, c);
	fflush(stdout);
	
	char s[10];
	scanf(" %s", s);
	
	if(s[0] == 'Y')
		return true;
	return false;
}

void addE(int u, int v){
	deg[u]++;
	deg[v]++;
}

vector <int> getPath(int from, vector <int> cur){
	if(cur.size() == 0)
		return vector <int> ();
	if(cur.size() == 1)
		return cur;
	
	random_shuffle(cur.begin(), cur.end());
	int mid = cur.back();
	
	cur.pop_back();
	vector <int> ret;
	
	vector <int> Left;
	vector <int> Right;

	for(int v: cur)
		if(ask(from, v, mid))
			Left.push_back(v);
		else
			Right.push_back(v);
	
	Left = getPath(from, Left);
	Right = getPath(from, Right);
	
	for(int v: Left)
		ret.push_back(v);
	ret.push_back(mid);

	for(int v: Right)
		ret.push_back(v);
	return ret;
}

void solve(int u, vector <int> cur){
	if(cur.size() == 1)
		return;
	
	int t;
	do
		t = cur[rand()%cur.size()];
	while(t == u);
	
	vector <int> path;
	for(int v: cur)
		if(ask(u, v, t))
			path.push_back(v);
	
	path = getPath(u, path);
	vector <int> where[path.size() + 5];
	
	for(int v: cur){
		int s = 0, e = path.size() - 1;
		while(s < e){
			int m = (s + e + 1) / 2;
			if(!ask(u, path[m], v))
				e = m - 1;
			else
				s = m;
		}
		
		where[s].push_back(v);
	}
	
	for(int i = 0; i + 1 < (int)path.size(); ++i)
		addE(path[i], path[i + 1]);
	
	for(int i = 0; i < (int)path.size(); ++i)
		solve(path[i], where[i]);
}

int main(){
	scanf("%d %d", &n, &k);

	if(n >= 20 && k >= n / 2 + 5){
		for(int i = 0; i < 60; ++i){
			int u, v;
			do
				u = rand()%n + 1,
				v = rand()%n + 1;
			while(u == v);

			for(int j = 1; j <= n; ++j)
				if(ask(u, j, v))
					++cnt[j];
		}
		
		int best = 1;
		for(int i = 1; i <= n; ++i)
			if(cnt[i] > cnt[best])
				best = i;
		
		printf("! %d\n", best);
		exit(0);
	}

	vector <int> cur;	
	for(int i = 1; i <= n; ++i)
		cur.push_back(i);
	solve((47 * n * n - 21 * n + 235252)%n + 1, cur);
	
	for(int i = 1; i <= n; ++i)
		if(deg[i] == k){
			printf("! %d\n", i);
			exit(0);
		}

	assert(false);
	return 0;
}