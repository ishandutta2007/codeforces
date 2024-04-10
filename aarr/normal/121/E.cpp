#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, A = 10 * 1000 + 5, SQ = 403;
int n, m;

int a[N];
int cnt[SQ][A];
int lazy[SQ];
vector <int> lcks;
bool lck[A];

bool is_lucky(int x) {
	while (x) {
		if (x % 10 != 7 && x % 10 != 4) {
			return false;
		}
		x /= 10;
	}
	return true;
}

void relax(int p) {
	for (int i = 0; i < A; i++) {
		cnt[p][i] = 0; 
	}
	for (int i = p * SQ; i < (p + 1) * SQ && i < n; i++) {
		a[i] += lazy[p];
		cnt[p][a[i]]++;
	}
	lazy[p] = 0;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i += SQ) {
		relax(i / SQ);
	}
	for (int i = 0; i < A; i++) {
		if (is_lucky(i)) {
			lcks.push_back(i);
			lck[i] = true;
		}
	}
	for (int i = 0; i < m; i++) {
		string qt;
		int l, r;
		cin >> qt >> l >> r;
		l--;
	//	relax(l / SQ);
	//	relax((r - 1) / SQ);
		if (qt == "count") {
			int ans = 0;
			while (l < r) {
				if (l % SQ != 0 || l + SQ >= r) {
				//	cout << "41 " << l << endl;
					if (lck[a[l] + lazy[l / SQ]]) {
						ans++;
					}
					l++;
				}
				else {
				//	cout << "42 " << l << endl;
					for (auto x : lcks) {
						if (x >= lazy[l / SQ]) {
							ans += cnt[l / SQ][x - lazy[l / SQ]];
						}
					}
					l += SQ;
				}
			}
			cout << ans << '\n';
		}
		else {
			int d;
			cin >> d;
			while (l < r) {
				if (l % SQ != 0 || l + SQ >= r) {
					cnt[l / SQ][a[l]]--;
					a[l] += d;
					cnt[l / SQ][a[l]]++;
					l++;
				}
				else {
					lazy[l / SQ] += d;
					l += SQ;
				}
			}
		}
	}
	return 0;
}