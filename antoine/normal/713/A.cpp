#include <iostream>
#include <string>

struct node {
	node * child[2];
	int count = 0;
	int endingHere = 0;
	node() { child[0] = child[1] = nullptr; }
};

node root;

int countMatches(const node &n, const std::string &a) {
	if (a.size() <= 0) {
		int count = n.endingHere;
		if(n.child[0] != nullptr)
			count += countMatches(*n.child[0], a);
		return count;
	}
	int count = 0;
	const int parity = a[a.size() - 1] - '0';
	if(n.child[parity] != nullptr)
		count += countMatches(*n.child[parity], a.substr(0, a.size() - 1));
	return count;
}

void removeLeftZeros(std::string &a) {
	if (a[0] == '0') {
		int idx = 1;
		while (idx < a.size() && a[idx] == '0')
			++idx;
		a = a.substr(idx);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	for (; t >= 1; --t) {
		std::string op, a;
		std::cin >> op >> a;
		removeLeftZeros(a);

		if (op[0] == '+') {
			node * n = &root;
			(*n).count++;
			for (int i = a.size() - 1; i >= 0; --i) {
				int digit = (a[i] - '0') % 2;
				if ((*n).child[digit] == nullptr)
					(*n).child[digit] = new node();
				n = (*n).child[digit];
				(*n).count++;
			}
			(*n).endingHere++;
		} else if (op[0] == '-') {
			node * n = &root;
			(*n).count--;
			for (int i = a.size() - 1; i >= 0; --i) {
				int digit = (a[i] - '0') % 2;
				n = (*n).child[digit];
				(*n).count--;
			}
			(*n).endingHere--;
		} else if(op[0] == '?')
			std::cout << countMatches(root, a) << "\n";
		else std::cout << "Error1";
	}
}