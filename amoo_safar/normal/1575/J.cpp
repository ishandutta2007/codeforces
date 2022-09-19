#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

set <pair <int, int> > s[N];


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				s[j].insert({i, x});
			}
			if (x == 3) {
				s[j].insert({i, x});
			}
		}
	}
	for (int i = 0; i < k; i++) {
		set <pair <int, int> > :: iterator it;
		int y, x = 0;
		cin >> y;
		while(true) {
			it = s[y].lower_bound({x, 0});
			if (it == s[y].end()) {
				break;
			}
			pair <int, int> p = *it;
			x = (*it).first;
			s[y].erase(it);
			if (p.second == 1) {
				y++;
			}	
			else {
				y--;
			}
		//	cout << "72 " << x << " " << y << endl;
			
		} 
		cout << y << endl;
	}
	return 0;
}