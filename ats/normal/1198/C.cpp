#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<int> es;
		vector<int> ns(3 * N, 0);
		int a, b;
		for (int i = 0; i < M; i++) {
			cin >> a >> b; a--; b--;
			if (ns[a] == 0 && ns[b] == 0) {
				ns[a] = 1;
				ns[b] = 1;
				es.push_back(i + 1);
			}
		}
		if (es.size() >= N) {
			cout << "Matching" << endl;
		}
		else {
			cout << "IndSet" << endl;
			es.clear();
			for (int i = 0; i < 3 * N; i++) {
				if (ns[i] == 0)es.push_back(i + 1);
			}
		}
			for (int i = 0; i < N; i++) {
				if (i > 0)cout << " ";
				cout << es[i];
			}
			cout << endl;
		
	}
}