#include <bits/stdc++.h>
using namespace std;

const int MAXN = 255;
const int BASE = 3137;
const int MOD = 1e9 + 7;

int N, M;
char s[MAXN][MAXN];
int hsh[MAXN][MAXN];
int mask[MAXN][MAXN];
int pot[30];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", s[i] + 1);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

bool check(int x) {
	return __builtin_popcount(x) <= 1;
}

int manacher(const vector <int> &v) {
	vector <int> nxt = {-1};
	for (auto it : v) {
		nxt.push_back(it);
		nxt.push_back(-1);
	}
	
	int sz = nxt.size();
	vector <int> p(sz, 0);
	
	int mx = 0, id = 0, res = 0;
	for (int i = 1; i < sz - 1; i++) {
		int lft = i - 1, rig = i + 1;
		if (i <= mx) {
			int sym = 2 * id - i;
			if (p[sym] < mx - i - 1) {
				p[i] = p[sym];
				lft = -1;
			}
			else {
				p[i] = mx - i;
				rig = mx + 1;
				lft = 2 * i - rig;
			}
		}
		for (; lft >= 0 && rig < sz && nxt[lft] == nxt[rig]; p[i]++) {
			lft--;
			rig++;
		}
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
		res += (p[i] + 1) / 2;
	}
	
	return res;
}

int solve() {
	pot[0] = 1;
	for (int i = 1; i < 26; i++)
		pot[i] = mul(pot[i - 1], BASE);
	
	for (int i = 0; i < N; i++)	
		for (int j = 1; j <= M; j++) {
			hsh[i][j] = add(hsh[i][j - 1], pot[s[i][j] - 'a']);
			mask[i][j] = mask[i][j - 1] ^ 1 << s[i][j] - 'a';
		}
	
	int sol = 0;
	for (int i = 1; i <= M; i++)
		for (int j = i; j <= M; j++) {
			vector <int> curr;
			for (int k = 0; k < N; k++) 
				if (check(mask[k][j] ^ mask[k][i - 1]))
					curr.push_back(add(hsh[k][j], -hsh[k][i - 1]));
				else {
					sol += manacher(curr);
					curr.clear();
				}
			sol += manacher(curr);
		}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}