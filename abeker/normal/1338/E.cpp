#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 8e3 + 5;

int N;
int idx[MAXN];
int dep[MAXN];
bool bio[MAXN];
vector <int> comp;
vector <int> in[MAXN], out[MAXN];
vector <int> tree[MAXN];
bool adj[MAXN][MAXN];
char buff[MAXN];
stack <int> S;
int curr;

void load() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		gets(buff);
		for (int j = 0; j < N / 4; j++) {
			int num = isdigit(buff[j]) ? buff[j] - '0' : buff[j] - 'A' + 10;
			for (int k = 0; k < 4; k++)
				if (num >> 3 - k & 1) {
					int tmp = 4 * j + k;
					out[i].push_back(tmp);
					in[tmp].push_back(i);
					adj[i][tmp] = true;
				}
		}
	}
}

void dfs_forward(int x) {
	bio[x] = true;
	for (auto it : out[x])
		if (!bio[it])
			dfs_forward(it);
	S.push(x);
}

void dfs_backward(int x) {
	bio[x] = true;
	idx[x] = curr;
	comp.push_back(x);
	for (auto it : in[x])
		if (!bio[it])
			dfs_backward(it);
}

bool cmp(const int &l, const int &r) {
	return in[l].size() < in[r].size();
}

int solve_component() {
	for (auto node : comp) {
		vector <int> tmp;
		for (auto it : in[node])
			if (idx[it] == curr)
				tmp.push_back(it);
		in[node] = tmp; 
	}
	
	sort(comp.begin(), comp.end(), cmp);
	
	int res = 0;
	tree[N].clear();
	for (auto node : comp) {
		int tmp = N;
		while (1) {
			int nxt = -1;
			for (auto it : tree[tmp])
				if (adj[it][node] && (nxt == -1 || adj[nxt][it]))
					nxt = it;
			if (nxt == -1)
				break;
			tmp = nxt;
		}
		bool subset = true;
		for (auto it : in[tmp])
			if (!adj[it][node]) {
				subset = false;
				break;
			}
		if (!subset)
			tmp = N;
		tree[tmp].push_back(node);
		dep[node] = dep[tmp] + 1;
		res += dep[tmp];
	}
	
	return res;
}

int choose(int n) {
	return n * (n - 1) / 2;
}

ll solve() {
	for (int i = 0; i < N; i++)
		if (!bio[i])
			dfs_forward(i);
	
	memset(bio, false, sizeof bio);
	
	int sol = 0, sum = 0;
	for (; !S.empty(); S.pop()) 
		if (!bio[S.top()]) {
			comp.clear();
			dfs_backward(S.top());
			sol += solve_component();
			sum += choose(comp.size());
			curr++;
		}
		
	return (ll)(614 * N + 1) * (choose(N) - sum) + 3 * sum + sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}