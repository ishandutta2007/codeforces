#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 500 + 10;

int n, m;
string s[maxn];
int a[maxn][maxn];
vector<int> g[maxn];
int topMatch[maxn], botMatch[maxn];
bool visited[maxn];

bool dfs(int v) {
	if (visited[v])
		return false;
	visited[v] = true;
	for (auto u : g[v])
		if (botMatch[u] == -1 || dfs(botMatch[u])) {
			botMatch[u] = v;
			topMatch[v] = u;
			return true;
		}
	return false;
}

int fastMatching(int n) {
	memset(topMatch, -1, sizeof topMatch);
	memset(botMatch, -1, sizeof botMatch);
	bool found = true;
	int answer = 0;
	while (found) {
		found = false;
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < n; i++) {
			if (topMatch[i] == -1) {
				bool foundPath = dfs(i);
				answer += foundPath;
				found |= foundPath;
			}
		}
	}
	return answer;
}

void add_edge(int topV, int botV) {
	g[topV].push_back(botV);
}

void solveOne() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int countOnes = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int xorFour = 0;
			for (int ix = 0; ix < 2; ix++)
				for (int jy = 0; jy < 2; jy++)
					if (i + ix < n and j + jy < m)
						xorFour ^= (s[i + ix][j + jy] == 'B');
			a[i][j] = xorFour;
			countOnes += a[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			if (a[i][m - 1] && a[i][j] && a[n - 1][j])
				add_edge(i, j);
	int answer = countOnes;
	int maximumMatching = fastMatching(n - 1);
	for (int k = 0; k <= maximumMatching; k++) {
		int remainingOnes = countOnes - 3 * k;
		if (k & 1) {
			if (a[n - 1][m - 1])
				remainingOnes--;
			else
				remainingOnes++;
		}
		answer = min(answer, remainingOnes + 2 * k);
	}
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t = 1;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}