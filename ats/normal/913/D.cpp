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
template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	T sum(int i, int j) {
		if (i == 0) {
			T S = 0;
			for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
			return S;
		}
		else return sum(0, j) - sum(0, i - 1);
	}
	void add(int k, T a) {
		for (; k < x.size(); k |= k + 1) x[k] += a;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, T;
	cin >> N >> T;
	vector<pair<pair<int, int>, int > > pa(N);
	vector<vector<int> > w(N + 1);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> pa[i].first.second >> pa[i].first.first;
		pa[i].second = i;
		//w[pa[i].second].push_back(i);
	}
	sort(pa.begin(), pa.end());
	for (int i = 0; i < N; i++) {
		w[pa[i].first.second].push_back(i);
	}
	fenwick_tree<int> ft(N);
	fenwick_tree<int> ft2(N);
	for (int i = 0; i < N; i++) {
		ft.add(i, pa[i].first.first);
		ft2.add(i, 1);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < w[i - 1].size(); j++) {
			//cerr << i <<" " <<  w[i][j] << endl;
			ft.add(w[i - 1][j], -pa[w[i - 1][j]].first.first);
			ft2.add(w[i - 1][j], -1);
		}
		int u = N;
		int d = -1;
		int m;
		while (u - d > 1) {
			m = (u + d) / 2;
			if (ft.sum(0, m) <= T) {
				d = m;
			}
			else {
				u = m;
			}
		}
		m = d;
		if (m == -1)continue;
		//cerr << ft.sum(0, m) << " " << ft.sum(0, m + 1) << endl;
		//cerr << i << " " << m << " " << ft2.sum(0, m) << endl;
		int k = min(i, ft2.sum(0, m));
		if (res < k) {
			res = k;
		}
	}
	cout << res << endl;
	cout << res << endl;
	//cout << res << endl;
	bool f = true;
	int c = 0;
	for (int i = 0; i < N; i++) {
		if (pa[i].first.second >= res) {
			if (c == res)break;
			if (!f)cout << " ";
			cout << pa[i].second + 1;
			f = false;
			c++;
			
		}
	}
	cout << endl;
}