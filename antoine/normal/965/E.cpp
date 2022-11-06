#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>

using namespace std;
typedef long long ll;

struct Trie {
	map<char, shared_ptr<Trie>> adj;
	int endCount = 0, depth, height = 0;

	Trie(const int depth) : depth(depth) {}

	bool empty() {
		return !endCount && adj.empty();
	}

	char computeHeight() {
		char choice = 0;
		height = 0;
		for (auto &&x : adj) {
			if (x.second->height >= height) {
				height = x.second->height + 1;
				choice = x.first;
			}
		}
		return choice;
	}

	void insert(const string &s, const int i) {
		if (i == s.size())
			endCount++;
		else {
			auto it = adj.find(s[i]);
			if (it != adj.end())
				it->second->insert(s, i + 1);
			else {
				auto next = make_shared<Trie>(depth + 1);
				next->insert(s, i + 1);
				adj[s[i]] = next;
			}
		}

		computeHeight();
	}

	void compress() {
		if (adj.empty()) return;

		for (auto &&x : adj)
			x.second->compress();

		char choice = computeHeight();

		if (endCount++) return;

		adj[choice]->rem();
		if (adj[choice]->empty())
			adj.erase(choice);
		
		computeHeight();
	}

	void rem() {
		if (adj.empty()) {
			endCount = 0;
			return;
		}

		char choice = computeHeight();

		adj[choice]->rem();
		if (adj[choice]->empty())
			adj.erase(choice);

		computeHeight();
	}


	int ans() {
		int res = endCount ? depth : 0;
		for (auto &&x : adj)
			res += x.second->ans();
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	Trie trie(0);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		trie.insert(s, 0);
	}

	for (auto &&x : trie.adj)
		x.second->compress();
	cout << trie.ans();
	return 0;
}