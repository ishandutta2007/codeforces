#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int N = 100 * 1000 + 5, LG = 19;

int a[N];
int f[N];
int rnk[N][LG + 5];
vector <pair <pair <int, int>, int> > vec;
stack <pair <int, int> > st;


int main() {
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		string s;
		cin >> s;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			rnk[i][0] = s[i] - 'a';
			f[i] = 0;
		}
		for (int j = 1; j <= LG; j++) {
			for (int i = 0; i < n; i++) {
				vec.push_back({{rnk[i][j - 1], -1}, i});
				if (i + (1 << (j - 1)) < n) {
					vec.back().first.second = rnk[i + (1 << (j - 1))][j - 1];
				}
			} 
			sort(vec.begin(), vec.end());
			int t = 0;
			for (int i = 0; i < n; i++) {
				if (i > 0 && vec[i].first != vec[i - 1].first) {
					t++;
				}
				rnk[vec[i].second][j] = t;
			}
		//	for (int i = 0; i < n; i++) {
		//		cout << "73 " << i << " " << j << " " << rnk[i][j] << endl;
		//	}
			vec.clear();
		}
		for (int i = 0; i < n; i++) {
			a[rnk[i][LG]] = i;
		}
		for (int i = 0; i < n - 1; i++) {
			int x = a[i], y = a[i + 1];
			for (int j = LG; j >= 0; j--) {
				if (rnk[x][j] == rnk[y][j]) {
				//	cout << "71 " << x << " " << y << " " << j << endl;
					x += 1 << j;
					y += 1 << j;
					f[i] += 1 << j;
				}
				if (x >= n || y >= n) {
					break;
				}
			}
		}
	//	for (int i = 0; i < n; i++) {
	//		cout << "72 " << a[i] << " " << f[i] << endl;
	//	}
		long long ans = 0;
		st.push({0, -1});
		for (int i = 0; i < n; i++) {
			st.push({n - a[i], i});	
			pair <int, int> p1 = {f[i], i};
			int k = i;
			while (st.top() > p1) {
				pair <int, int> p2 = st.top();
				st.pop();
			//	cout << "74 " << (p2.first - max(p1.first, st.top().first)) << " " << (i - p2.second + 1) << endl;
				ans += 1ll * (p2.first - max(p1.first, st.top().first)) * (i - p2.second + 1) * (i - p2.second + 1);
				k = p2.second;
			}	
			st.push({f[i], k});
		}
		cout << ans << endl;
	}

	return 0;
}