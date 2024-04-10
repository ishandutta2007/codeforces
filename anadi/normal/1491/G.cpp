#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const LL INF = 1LL * MOD * MOD;

int n;
int in[N];

int m;
bool vis[N];
vector <int> cycles[N];

void debug(vector <PII> ans) {
	auto wypisz = [&]() {
		for(int i = 1; i <= n; ++i)
			printf("%d ", in[i]);
		puts("");
	};
	
	wypisz();
	for(auto [x, y]: ans) {
		swap(in[x], in[y]);
		in[x] *= -1, in[y] *= -1;
		wypisz();
	}
	
	for(int i = 1; i <= n; ++i)
		assert(in[i] == i);
}

void write(vector <PII> ans) {
//	debug(ans);
	printf("%d\n", (int)ans.size());
	for(auto [u, v]: ans)
		printf("%d %d\n", u, v);
	exit(0);
}

void brute() {
	vector <int> cur(n);
	for(int i = 0; i < n; ++i)
		cur[i] = in[i + 1];

	map <vector <int>, PII> P;
	P[cur] = {-1, -1};
	
	queue <vector <int> > Q;
	Q.push(cur);
	
	while(!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j) {
				auto nxt = u;
				swap(nxt[i], nxt[j]);
				nxt[i] *= -1, nxt[j] *= -1;
				
				if(!P.count(nxt)) {
					P[nxt] = {i, j};
					Q.push(nxt);
				}
			}
	}
	
	iota(cur.begin(), cur.end(), 1);
	assert(P.count(cur));
	
	vector <PII> ans;
	while(P[cur] != make_pair(-1, -1)) {
		auto [x, y] = P[cur];
		ans.push_back({x, y});
		
		swap(cur[x], cur[y]);
		cur[x] *= -1, cur[y] *= -1;
	}
	
	reverse(ans.begin(), ans.end());
	for(auto &[x, y]: ans)
		x++, y++;
	write(ans);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	if(n <= 3)
		brute();
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			int cur = i;			
			while(!vis[cur]) {
				cycles[m].push_back(cur);
				vis[cur] = true;
				cur = in[cur];
			}
			
			m++;
		}
	
	vector <PII> ans;
	for(int i = 0; i + 1 < m; i += 2) {
		int any = cycles[i + 1][0];
		for(auto v: cycles[i])
			ans.push_back({any, v});
		
		any = cycles[i][0];
		int s = cycles[i + 1].size();
		
		for(int j = 0; j < s; ++j)
			ans.push_back({any, cycles[i + 1][(j + 1) % s]});
	}
	
	if(m & 1) {
		auto cycle = cycles[m - 1];
		int s = cycle.size();
		
		if(s == n) {
			for(int i = 1; i < s - 1; ++i)
				ans.push_back({cycle[0], cycle[i]});
			
			ans.push_back({cycle[1], cycle[n - 1]});
			ans.push_back({cycle[0], cycle[n - 1]});
			ans.push_back({cycle[0], cycle[1]});
		} else {
			for(int i = 0; i < s; ++i)
				ans.push_back({1, cycle[i]});
			ans.push_back({1, cycle[0]});
		}
	}

	write(ans);
	return 0;
}