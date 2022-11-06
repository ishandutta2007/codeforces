#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

int n;
vector<int> children[1001];
bool isLeaf[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		children[p].push_back(i);
	}

	for (int i = 1; i <= n; ++i)
		isLeaf[i] = i > 1 && children[i].empty();

	for (int i = 1; i <= n; ++i)
		if (!isLeaf[i]) {
			int count = 0;
			for (auto &&x : children[i])
				if (isLeaf[x])
					++count;
			if (count < 3) {
				cout << "No";
				return 0;
			}
		}
	cout << "Yes";
	return 0;
}