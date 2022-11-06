#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void No() {
	cout << "NO\n";
	exit(0);
}
struct Edge {
	string name;
	bool used = false;
};

struct Node {
	string name;
	vector<vector<Edge>::iterator> adj;
	vector<vector<Edge>::iterator>::iterator adjIt;
	int inDeg = 0, outDeg = 0;

	Node(string name) :
			name(name) {
		adjIt = adj.begin();
	}

	Node(const Node &other) {
		name = other.name;
		adj = other.adj;
		adjIt = adj.begin();
		inDeg = other.inDeg;
		outDeg = other.outDeg;
	}

	bool done() {
		while (adjIt != adj.end() && (*adjIt)->used) {
						++adjIt;
		}
		return adjIt == adj.end();
	}
};

map<string, Node> nodeMp;
vector<Edge> edges;
string res;

void dfs(Node &node) {
	while (!node.done()) {
		Edge &e = **(node.adjIt++);
		e.used = true;
		dfs(nodeMp.at(e.name.substr(1)));
	}
	res += node.name.back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	edges.reserve(n+100);

for(int rep = 0; rep < n; ++rep) {
		string s;
		cin >> s;

		string uName = s.substr(0, 2);
		string vName = s.substr(1, 2);

		Node &u = nodeMp.insert( { uName, { uName } }).first->second;
		Node &v = nodeMp.insert( { vName, { vName } }).first->second;

		edges.push_back( { s });
		u.adj.push_back(edges.end() - 1);
		u.adjIt = u.adj.begin(); //////////

		++u.outDeg;
		++v.inDeg;
	}

	Node * start = nullptr, *end = nullptr;

	for (auto &&e : nodeMp) {
		Node &node = e.second;
		if (node.inDeg + 1 == node.outDeg) {
			if (start && start->inDeg + 1 == start->outDeg)
				No();
			start = &node;
		} else if (node.inDeg == node.outDeg) {
			if (!start)
				start = &node;
			else if (!end)
				end = &node;
		} else if (node.inDeg == node.outDeg + 1) {
			if (end && end->inDeg == end->outDeg + 1)
				No();
			end = &node;
		} else
			No();
	}

	dfs(*start);

	if((int)res.size() != n + 1) {
		cerr << "not n + 1 : " << res.size() << ' ' << res << endl;
		No();
	}
	cout << "YES\n";
	reverse(res.begin(), res.end());
	cout << start->name[0] << res << '\n';

	return 0;
}