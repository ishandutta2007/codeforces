
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



int main()
{
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n ;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		int lo = 0;
		int hi = n + 1;
		while (hi - lo > 1) {
			int md = (lo + hi) / 2;
			int taken = 0;
			for (int i = 0; i < n; i++) {
				if (v[i].first >= md - 1 - taken && v[i].second >= taken) taken++;
			}
			if (taken >= md) lo = md;
			else hi = md;
		}
		cout << lo << endl;
	}

}