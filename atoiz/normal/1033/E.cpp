#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cassert>

using namespace std;

int ask(vector<int> vec)
{
	#ifdef LOCAL
	int A = 0;
	for (int i = 0; i < (int) vec.size(); ++i) for (int j = 0; j < i; ++j) {
		if (vec[i] <= 100 && vec[j] > 100) ++A;
		if (vec[i] > 100 && vec[j] <= 100) ++A;
	}
	return A;
	#endif

	if ((int) vec.size() <= 1) return 0;
	cout << "? " << vec.size();
	for (int u : vec) cout << ' ' << u;
	cout << endl;
	int ans;
	cin >> ans;
	assert(ans != -1);
	return ans;
}

int getEdge(int from, vector<int> vec)
{
	vec.insert(vec.begin(), from);
	int cnt = ask(vec) - ask(vector<int>(vec.begin() + 1, vec.end()));
	if (cnt == 0) return 0;

	while ((int) vec.size() > 2) {
		int split = ((int) vec.size() + 1) / 2;
		int cur = ask(vector<int>(vec.begin(), vec.begin() + split)) - ask(vector<int>(vec.begin() + 1, vec.begin() + split));
		if (cur == split - 1) return vec[1];
		else if (cnt - cur == (int) vec.size() - split) return vec.back();
		else if (cur == cnt) vec.resize(split);
		else {
			rotate(vec.begin() + 1, vec.begin() + split, vec.end());
			vec.resize((int) vec.size() - (split - 1));
			cnt -= cur;
		}
	}
	assert(cnt);
	return vec[1];
}

const int MAXN = 607;
int N;
vector<int> G[MAXN], part[2];

void dfs(int u, int p, int k)
{
	part[k].push_back(u);
	for (int v : G[u]) if (v != p) dfs(v, u, k ^ 1);
}

vector<int> path;
bool getPath(int u, int p, int to)
{
	if (u == to) {
		path.push_back(u);
		return true;
	}

	for (int v : G[u]) if (v != p && getPath(v, u, to)) {
		path.push_back(u);
		return true;
	}
	return false;
}

int main()
{
	cin >> N;

	vector<int> out(N - 1), in(1, 1);
	iota(out.begin(), out.end(), 2);
	for (int i = 0; i < (int) in.size(); ++i) {
		int u = in[i], v;
		while ((v = getEdge(u, out))) {
			G[u].push_back(v);
			G[v].push_back(u);
			in.push_back(v);
			out.erase(find(out.begin(), out.end(), v));
		}
	}
	assert(out.empty());

	dfs(1, 0, 0);
	vector<int> vec;
	if (ask(part[0])) vec = part[0];
	else if (ask(part[1])) vec = part[1];
	else {
		cout << "Y " << (int) part[0].size() << endl;
		for (int i = 0; i < (int) part[0].size(); ++i) cout << part[0][i] << " \n"[i == (int) part[0].size() - 1];
		cout << flush;
		return 0;
	}

	int from = -1, to;
	while (!vec.empty()) {
		int u = vec.back(), v;
		vec.pop_back();
		if ((v = getEdge(u, vec))) {
			from = u, to = v;
			break;
		}
	}
	assert(from != -1);
	// cout << "path " << from << ' ' << to << endl;

	bool hasPath = getPath(from, 0, to);
	assert(hasPath && (int) path.size() & 1);
	cout << "N " << (int) path.size() << endl;
	for (int i = 0; i < (int) path.size(); ++i) cout << path[i] << " \n"[i == (int) path.size() - 1];
	cout << flush;
	return 0;
}