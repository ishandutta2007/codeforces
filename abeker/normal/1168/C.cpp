#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int LOG = 19;
const int MAXP = LOG * (LOG - 1) / 2;

int N, Q;
int a[MAXN];
int idx[LOG][LOG];
int last[MAXN][MAXP];
vector <pii> jumps[MAXN];

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void go(int x) {
	int curr = x, sofar = 0;
	while (curr < N) {
		sofar |= a[curr];
		jumps[x].push_back({curr, sofar});
		vector <int> v[2];
		for (int i = 0; i < LOG; i++)
			v[sofar >> i & 1].push_back(i);
		int nxt = N;
		for (auto it0 : v[0])
			for (auto it1 : v[1])
				if (last[curr + 1][idx[it0][it1]] < nxt)
					nxt = last[curr + 1][idx[it0][it1]];
		curr = nxt;
	}
}

bool query(int x, int y) {
	return ((--upper_bound(jumps[x].begin(), jumps[x].end(), pii(y, 0))) -> second) & a[y]; 
}

void solve() {
	int tmp = 0;
	for (int i = 0; i < LOG; i++)
		for (int j = i + 1; j < LOG; j++)
			idx[i][j] = idx[j][i] = tmp++;
	assert(tmp == MAXP);
	
	for (int i = 0; i < MAXP; i++)
		last[N][i] = N;
		
	for (int i = N - 1; i >= 0; i--) {
		vector <int> bits;
		for (int j = 0; j < LOG; j++)
			if (a[i] >> j & 1)
				bits.push_back(j);
		memcpy(last[i], last[i + 1], sizeof last[i]);
		for (int k = 0; k < bits.size(); k++)
			for (int j = 0; j < k; j++)
				last[i][idx[bits[j]][bits[k]]] = i;
	}
	
	for (int i = 0; i < N; i++)
		go(i);		 
	
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		puts(query(--x, --y) ? "Shi" : "Fou"); 
	}
}

int main() {
	load();
	solve();
	return 0;
}