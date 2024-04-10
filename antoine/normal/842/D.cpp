#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <vector>

class Trie {
	struct Node { Node * next[2]; };
	Node * root;
public:
	Trie() { root = new Node(); }

	void insert(int x) {
		Node * curr = root;
		int bit = 1 << 20;
		do {
			bool way = x&bit;
			if (curr->next[way] == nullptr)
				curr->next[way] = new Node();
			curr = curr->next[way];
			bit >>= 1;
		} while (bit != 0);
	}

	int min(int x) {
		Node * curr = root;
		int bit = 1 << 20;
		int min = 0;
		do {
			bool way = x&bit;
			if (curr->next[way] == nullptr) {
				way = !way;
				min |= bit;
			}
			curr = curr->next[way];
			bit >>= 1;
		} while (bit != 0);
		return min;
	}
};

int n, m;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	std::unordered_set<int> a;
	a.reserve(600000);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		a.insert(x);
	}
	Trie trie;
	for (int i = 0; i < (1 << 20); ++i)
		if (!a.count(i))
			trie.insert(i);
	int x = 0;
	while (--m >= 0) {
		int q;
		std::cin >> q;
		x ^= q;
		std::cout << trie.min(x) << '\n';
	}
	return 0;
}