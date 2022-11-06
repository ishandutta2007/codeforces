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
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	typedef pair<int, int> pii;

	priority_queue<pii, vector<pii>, greater<pii>> pq1;
	priority_queue<pii> pq2;
	
	for (int i = 1; i <= n; ++i) {
		int w;
		cin >> w;
		pq1.emplace(w, i);
	}
	
	
	string s;
	cin >> s;
	for (char c : s) {
		if (c == '0') {
			cout << pq1.top().second << ' ';
			pq2.emplace(pq1.top());
			pq1.pop();
		}
		else {
			cout << pq2.top().second << ' ';
			pq2.pop();
		}
	}
	return 0;
}