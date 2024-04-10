#include <iostream>
#include <deque>
using namespace std;
 
const int N = 100 * 1000 + 5, SQ = 507, SQs = 375;
int n;
 
int a[N];
deque<int> b[SQs + 5];
int cnt[SQs + 5][N];
void makea() {
	int j = 0;
	for (int i = 0; i < SQs; i++) {
		for (auto x : b[i]) {
			a[j] = x;
			j++;
		}
	}
}
void makeb() {
	for (int i = 0; i < SQs; i++) {
		for (auto x : b[i]) {
		//	cout << "77 " << x << endl;
			cnt[i][x] = 0;
		}
		b[i].clear();
	}
//	cout << 76 << endl;
	for (int i = 0; i < n; i++) {
		b[i / SQ].push_back(a[i]);
		cnt[i / SQ][a[i]]++;
	}
}
int get(int l, int r, int k) {
	int s = 0, ans = 0;
	for (int i = 0; i < SQs; i++) {
		if (b[i].size() != 0) {
		/*	if (s < l && l <= s + b[i].size() && s < r && r <= s + b[i].size()) {
				for (int j = 0; j < b[i].size(); j++) {
					if (s + j + 1 <= r && l <= s + j + 1 && b[i][j] == k) {
						ans++;
					}
				}
				break;
			}*/
			if ((s < l && l <= s + b[i].size()) || (s < r && r <= s + b[i].size())) {
				for (int j = 0; j < b[i].size(); j++) {
					if (s + j + 1 <= r && l <= s + j + 1 && b[i][j] == k) {
						ans++;
					}
				}
			}
		/*	if (s < r && r <= s + b[i].size()) {
				for (int j = 0; j < b[i].size(); j++) {
					if (s + j + 1 <= r && l <= s + j + 1 && b[i][j] == k) {
						ans++;
					}
				}
			}*/
			else {
				if (l <= s && r > s + b[i].size()) {
					ans += cnt[i][k];
				}
			}
		}
		s += b[i].size();
	}
	return ans;
}
void update(int l, int r) {
	int s = 0;
	int val = 0;
	pair <int, int> p;
	bool c = false;
	for (int i = 0; i < SQs; i++) {
		if (b[i].size() != 0) {
			if (s < l && l <= s + b[i].size() && s < r && r <= s + b[i].size()) {
			//	cout << "81 " << endl;
				int x = b[i][r - s - 1];
				for (int j = r - s - 1; j >= l - s; j--) {
					b[i][j] = b[i][j - 1];
				}
				b[i][l - s - 1] = x;
				c = true;
				break;
			}
			if (s < l && l <= s + b[i].size()) {
				p = {i, l - s - 1};
				b[i].push_back(b[i].back());
				for (int j = (int) b[i].size() - 2; j >= l - s; j--) {
					b[i][j] = b[i][j - 1];
				}
				s += b[i].size() - 1;
				continue;
			}
			if (s < r && r <= s + b[i].size()) {
				val = b[i][r - s - 1];
				cnt[i][val]--;
				for (int j = r - s - 1; j > 0; j--) {
					b[i][j] = b[i][j - 1];
				}
				b[i].pop_front();
				s++;
				break;
			}
		}
		s += b[i].size();
	}
//	cout << "48 " << l << " " << r << " " << p.first << " " << p.second << " " << val << endl;
	if (c) {
		return;
	}
	cnt[p.first][val]++;
	b[p.first][p.second] = val;	
//	cout << 73 << endl;
}
int main() { 
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	makeb();
	int q;
	cin >> q;
	int lastans = 0;
	for (int i = 0; i < q; i++) {
		int qt;
		cin >> qt;
		int l, r, k = 0;
		cin >> l >> r;
		if (qt == 2) {
			cin >> k;
		}
		l = (l + lastans - 1) % n, r = (r + lastans - 1) % n, k = (k + lastans - 1) % n;
		l++, r++, k++;
		if (l > r) {
			swap(l, r);
		}
		if (qt == 1) {
			update(l, r);
		}
		else {
			lastans = get(l, r, k);
			cout << lastans << '\n';
		}
		if (i % SQ == 0) {
			makea();
		//	for (int j = 0; j < n; j++) {
		//		cout << a[j] << " ";
		//	}
		//	cout << 74 << endl;
			makeb();
		//	cout << 75 << endl;
		}
	}
	return 0;
}