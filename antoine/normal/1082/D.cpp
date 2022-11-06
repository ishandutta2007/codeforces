#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
	int id, deg;
	bool taken = false;
	bool operator<(const Node &other) const {
		if (taken != other.taken)
			return !taken;
		return deg < other.deg;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<Node> nodes(n);
	for (int i = 0; i < n; ++i) {
		cin >> nodes[i].deg;
		nodes[i].id = i + 1;
	}

	sort(nodes.begin(), nodes.end());

	vector<pair<int, int>> edges;

	{
		int last = nodes[0].id;
		for (int i = 2; i < n; ++i)
			if (nodes[i].deg > 1) {
				nodes[i].deg -= 2;
				nodes[i].taken = true;
				edges.emplace_back(last, nodes[i].id);
				last = nodes[i].id;
			}

		edges.emplace_back(last, nodes[1].id);
	}

	const int diam = (int) edges.size();

	nodes.erase(nodes.begin(), nodes.begin() + 2);
	while (!nodes.empty()) {
		sort(nodes.begin(), nodes.end());
		if (nodes[0].taken)
			break;
		if (nodes[0].deg == 0) {
			nodes.erase(nodes.begin());
			continue;
		}

		bool ok = false;
		for (int i = 1; i < (int) nodes.size(); ++i)
			if (nodes[i].deg > 1 || (nodes[i].taken && nodes[i].deg)) {
				nodes[i].deg--;
				edges.emplace_back(nodes[0].id, nodes[i].id);
				ok = true;
				break;
			}

		if (!ok) {
			cout << "NO\n";
			return 0;
		}

		nodes.erase(nodes.begin());
	}

	cout << "YES " << diam << '\n' << edges.size() << '\n';
	for (auto &&x : edges)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}