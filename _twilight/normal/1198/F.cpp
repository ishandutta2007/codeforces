#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;
const int K = 9;
const int C = 35005;

int gcd(int a, int b) {
	return (!b) ? (a) : (gcd(b, a % b)); 
}

int n;
int a[N];

namespace subtask1 {

	int G[1 << 20];
	void solve() {
		G[0] = 0;
		for (int s = 1; s < (1 << n); s++) {
			for (int i = 0; i < n; i++) {
				if ((s >> i) & 1) {
					G[s] = gcd(G[s ^ (1 << i)], a[i + 1]);	
					break;
				}
			}
		}
		int all = (1 << n) - 1;
		for (int s = 1; s < all; s++) {
			if (G[s] == 1 && G[all ^ s] == 1) {
				puts("YES");
				for (int i = 0; i < n; i++) {
					putchar('1' + ((s >> i) & 1));
					putchar(' ');
				}
				return;
			}
		}
		puts("NO");
	}

}

namespace subtask2 {
	
	int m;
	int used[20];
	vector<int> p1, p2, P;
	bitset<512> f[200][512];
	int s1[200], s2[200], id[200];

	void merge() {
		P.clear();
		vector<int>::iterator pa = p1.begin(), pb = p2.begin();
		while (pa != p1.end() && pb != p2.end()) {
			if (*pa < *pb) {
				P.push_back(*(pa++));
			} else if (*pa > *pb) {
				P.push_back(*(pb++));
			} else {
				P.push_back(*pa);
				pa++, pb++;
			}
		}
		while (pa != p1.end())
			P.push_back(*(pa++));
		while (pb != p2.end())
			P.push_back(*(pb++));
	}

	boolean ans[N];
	void work(int px, int py) {
		int x = a[px], y = a[py];
		int X = x, Y = y;
		m = 0;
		p1.clear();
		p2.clear();
		memset(used, false, sizeof(used));
		for (int i = 2; i * i <= X; i++) {
			if (!(X % i)) {
				p1.push_back(i);
				while (!(X % i))
					X /= i;
			}
		}
		if (X > 1)
			p1.push_back(X);
		for (int i = 2; i * i <= Y; i++) {
			if (!(Y % i)) {
				p2.push_back(i);
				while (!(Y % i))
					Y /= i;
			}
		}
		if (Y > 1)
			p2.push_back(Y);
		merge();
		int lim = 2;
		int sz1 = p1.size(), sz2 = p2.size();
		int all1 = (1 << sz1) - 1, all2 = (1 << sz2) - 1;
		for (int i = 1; i <= n; i++) {
			if (i == px || i == py)
				continue;
			boolean aflag = false;
			for (int j = 0; j < (signed) p1.size() && !aflag; j++) {	
				if ((a[i] % p1[j]) && used[j] < lim) {
					aflag = true;
					used[j]++;
				}
			}
			for (int j = 0; j < (signed) p2.size() && !aflag; j++) {	
				if ((a[i] % p2[j]) && used[j + sz1] < lim) {
					aflag = true;
					used[j + sz1]++;
				}
			}
			if (!aflag) {
				continue;
			}
			int sa = 0, sb = 0;
			for (int j = 0; j < (signed) p1.size(); j++)
				if (a[i] % p1[j])
					sa |= 1 << j;
			for (int j = 0; j < (signed) p2.size(); j++)
				if (a[i] % p2[j])
					sb |= 1 << j;
			s1[++m] = sa;
			s2[m] = sb;
			id[m] = i;
		}
		f[0][0].set(0);
		for (int i = 1; i <= m; i++) {
			for (int s0 = 0; s0 < (1 << sz1); s0++)
				f[i][s0].reset();
			for (int a0 = 0; a0 < (1 << sz1); a0++) {
				if (f[i - 1][a0].count()) {
					for (int a1 = 0; a1 < (1 << sz2); a1++) {
						if (f[i - 1][a0].test(a1)) {
							f[i][a0 | s1[i]].set(a1);
//							g[i][a0 | s1[i]][a1] = (a0 << sz2) | a1;
							f[i][a0].set(a1 | s2[i]);
//							g[i][a0][a1 | s2[i]] = (a0 << sz2) | a1;
						}
					}
				}
			}
			if (f[i][all1].test(all2)) {
				int b0 = all1, b1 = all2, c0, c1;
				c1 = b1;
				for (int j = i; j; j--) {
					for (c0 = 0; c0 < (1 << sz1); c0++) {
						if (f[j - 1][c0].test(c1) && ((c0 | s1[j]) == b0)) {
							goto fin;							
						}
					}
					c0 = b0;
					for (c1 = 0; c1 < (1 << sz2); c1++) {
						if (f[j - 1][c0].test(c1) && ((c1 | s2[j]) == b1)) {
							goto fin;
						}
					}
					assert(false);
fin: 
					if (c1 ^ b1) {
						ans[id[j]] = true;
					}
					b0 = c0, b1 = c1;
				}
				puts("YES");
				ans[py] = true;
				for (int j = 1; j <= n; j++) {
					putchar('1' + ans[j]);
					putchar(' ');
				}
				exit(0);
			}
		}
	}

	void solve() {
		double P = 1, p = 1.0 * K / (n - 1);
		srand((unsigned) time (NULL));
		for ( ; P > 1e-7; P = P * p) {
			int x = rand() % n + 1, y;
			while ((y = rand() % n + 1) == x);
			work(x, y);
		}
		puts("NO");
	}

}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	if (n <= 20) {
		subtask1::solve();
	} else {
		subtask2::solve();
	}
	return 0;
}