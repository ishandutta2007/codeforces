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
#include <stack>


using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, m;
	cin >> n >> k >> m;
	vector<string> words;
	vector<int> cost;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		words.push_back(s);
	}
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		cost.push_back(c);
	}
	map<string, int> groupMp;
	for (int i = 0; i < k; ++i) {
		int count;
		cin >> count;
		while (count--) {
			int num;
			cin >> num;
			groupMp[words[num-1]] = i;
		}
	}
	vector<int> costMp(k, 1e9);
	for (int i = 0; i < n; ++i)
		costMp[groupMp[words[i]]] = min(costMp[groupMp[words[i]]], cost[i]);
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		ans += costMp[groupMp[s]];
	}
	cout << ans;
	return 0;
}