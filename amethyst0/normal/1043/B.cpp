#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

#define ll long long

using namespace std;

const int maxn = 1010;
int v[maxn];

int main() {
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		v[i] -= v[i - 1];
	}
	
	vector <int> ans;
	
	for (int k = 1; k <= n; k++) {
		bool fl = true;
		for (int j = k; j < n; j++) {
			if (v[j] != v[j - k]) {
				fl = false;
				break;
			}
		}
		
		if (fl) {
			ans.push_back(k);
		}
	}
	
	cout << ans.size() << endl;
	
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}