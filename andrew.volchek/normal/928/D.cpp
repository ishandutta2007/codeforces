#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node {
	map<char, int> sons;
	int is_end = 0;
	int cnt = 0;
};

vector<Node> nodes;

int get_new_node() {
	nodes.push_back(Node());
	return (int)nodes.size() - 1;
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	
	string s;
	int ans = 0;
	vector<string> words;
	while (getline(cin, s)) {
		ans += s.size() + 1;
		string cur;
		for (auto c : s) {
			if (isalpha(c)) {
				cur += c;
			} else if (!cur.empty()) {
				words.push_back(cur);
				cur = "";
			}
		}
		if (!cur.empty()) {
			words.push_back(cur);
		}
	}
	int root = get_new_node();
	
	for (const auto& word : words) {
		int cur = root;
		vector<int> st = {cur};
		int start = -1, end = -1;
		for (size_t i = 0; i < word.size(); ++i) {
			int c = word[i];
			int nxt;
			if (nodes[cur].sons.count(c)) {
				nxt = nodes[cur].sons[c];
			} else {
				nxt = get_new_node();
				nodes[cur].sons[c] = nxt;
			}
			st.push_back(nxt);
			if (nodes[nxt].cnt == 1) {
				if (start == -1) {
					start = i;
				}
				if (nodes[nxt].is_end == 1) {
					end = i;
				}
			}
			cur = nxt;
		}
		if (end != -1) {
			ans -= max(0, end - start - 1);
		}
		if (nodes[cur].is_end == 0) {
			nodes[cur].is_end = 1;
			for (auto x : st) {
				++nodes[x].cnt;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}