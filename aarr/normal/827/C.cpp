#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
int n;

int fen[N][12][12][6];

string s;
int a[N];
char nuc[] = {' ', 'A', 'C', 'G', 'T'};

void update(int x, int od, int nw) {
	for (int i = 1; i <= 10; i++) {
		int y;
		for (y = x; y <= n; y += y & -y) {
			fen[y][i][x % i][od]--;
			fen[y][i][x % i][nw]++;
		}
	}
}
int get(int l, int r, int x, int y, int val) {
	int ans = 0;
	for (r; r > 0; r -= r & -r) {
		ans += fen[r][x][y][val];
	}
	for (l; l > 0; l -= l & -l) {
		ans -= fen[l][x][y][val];
	}
	return ans;
}
int main() {
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		int x;
		for (int j = 1; j <= 4; j++) {
			if (nuc[j] == s[i]) {
				x = j;
			}
		}
		update(i + 1, 0, x);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int x, od, nw;
			char c;
			cin >> x >> c;
			for (int j = 1; j <= 4; j++) {
				if (s[x - 1] == nuc[j]) {
					od = j;
				}
				if (c == nuc[j]) {
					nw = j;
				}
			}
			update(x, od, nw);
			s[x - 1] = c;
		}
		else {
			int l, r;
			cin >> l >> r;
			string e;
			cin >> e;
			int ans = 0;
			for (int j = 0; j < e.size() && j + l <= n; j++) {
				int val;
				for (int k = 1; k <= 4; k++) {
					if (e[j] == nuc[k]) {
						val = k;
					}
				}
			//	cout << "73 " << l - 1 << " " <<  
				ans += get(l - 1, r, e.size(), (l + j) % e.size(), val);
			}
			cout << ans << endl;
		}
	}
	return 0;
}