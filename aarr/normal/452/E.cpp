#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int N = 301 * 1000 + 5, LG = 20, mod = 1000 * 1000 * 1000 + 7;

int ps1[N], ps2[N], ps3[N];
int a[N];
long long b[N];
long long c[N];
int f[N];
int rnk[N][LG + 5];
vector <pair <pair <int, int>, int> > vec;
stack <pair <int, int> > st;


int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	string s = s1 + ((char) 96) + s2 + ((char) 95) + s3;
//	cout << s << endl;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		rnk[i][0] = s[i] - 'a' + 10;
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
	for (int i = 2; i < n - 1; i++) {
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
	for (int i = 2; i < n; i++) {
		ps1[i] = ps1[i - 1], ps2[i] = ps2[i - 1], ps3[i] = ps3[i - 1];
		int x = a[i];
		if (x < s1.size()) {
			ps1[i]++;
		}
		else {
			if (x <= s1.size() + s2.size()) {
				ps2[i]++;
			}
			else {
				ps3[i]++;
			}
		}
//		cout << "78 " << i << " " << ps1[i] << " " << ps2[i] << " " << ps3[i] << endl; 
	}
//	for (int i = 0; i < n; i++) {
//		cout << "72 " << a[i] << " " << f[i] << endl;
//	}
	st.push({0, 1});
	for (int i = 2; i < n; i++) {
		pair <int, int> p1 = {f[i], i};
		int k = i - 1;
		while (st.top() > p1) {
			pair <int, int> p2 = st.top();
			st.pop();
		//	cout << "74 " << (ps1[i] - ps1[p2.second]) << " " << (ps2[i] - ps2[p2.second]) << " " << (ps3[i] - ps3[p2.second]) << endl;
			b[p2.first + 1] -= 1ll  * (ps1[i] - ps1[p2.second]) * (ps2[i] - ps2[p2.second]) * (ps3[i] - ps3[p2.second]);
			b[max(p1.first, st.top().first) + 1] += 1ll  * (ps1[i] - ps1[p2.second]) * (ps2[i] - ps2[p2.second]) * (ps3[i] - ps3[p2.second]);
			k = p2.second;
		}	
		st.push({f[i], k});
	}
	c[0] = b[0];
	int mini = min(min(s1.size(), s2.size()), s3.size());
	for (int i = 1; i <= mini; i++) {
		c[i] = c[i - 1] + b[i];
		cout << c[i] % mod << " ";
	}
	return 0;
}