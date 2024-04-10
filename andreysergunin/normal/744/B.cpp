#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9 + 10;

int n;

vector<int> request(const vector<int> &a) {
	cout << sz(a) << endl;
	for (int i = 0; i < sz(a); ++i)
		cout << a[i] + 1 << " ";
	cout << endl;

	vector<int> res(n);
	for (int i = 0; i < n; ++i)
		cin >> res[i];

	return res;

}


int main() {
	cin >> n;

	vector<int> ans(n, INF);

	for (int i = 0; i < 10; ++i) {
		vector<int> a;
		vector<int> b;
		for (int j = 0; j < n; ++j) {
			if (j & (1 << i))
				a.push_back(j);
			else 
				b.push_back(j);
		}

		if (sz(a) > 0) {
			vector<int> res = request(a);

			for (int j = 0; j < n; ++j) {
				if (!(j & (1 << i)))
					ans[j] = min(ans[j], res[j]);
			}
		}

		if (sz(b) > 0) {
			vector<int> res = request(b);

			for (int j = 0; j < n; ++j) {
				if (j & (1 << i))
					ans[j] = min(ans[j], res[j]);
			}
		}
	}

	cout << -1 << endl;
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}