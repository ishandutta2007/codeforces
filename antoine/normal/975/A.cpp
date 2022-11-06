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
#include <numeric>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	set<set<char>> s;
	for (int i = 0; i < n; ++i) {
		string w;
		cin >> w;
		s.insert(set<char>(w.begin(), w.end()));
	}
	cout << s.size();
	return 0;
}