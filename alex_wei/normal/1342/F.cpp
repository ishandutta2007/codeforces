#include <bits/stdc++.h>
using namespace std;

const int N = 16;
struct dat {int msk, num, pos;} tr[1 << N][N][N];
int T, n, a[N], ban[N], s[1 << N], f[1 << N][N][N];
vector <pair <int, int>> ans;
int find(int x) {
	int rnk = 1;
	for(int i = 1; i < x; i++) if(!ban[i]) rnk++;
	return rnk;
}
void calc(int msk, int num, int pos) {
	if(!msk) return;
	dat t = tr[msk][num][pos];
	calc(t.msk, t.num, t.pos);
	for(int i = 0; i < n; i++)
		if(msk - t.msk >> i & 1 && i != pos - 1)
			ans.push_back({i + 1, pos});
}
void solve() {
	cin >> n, ans.clear();
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < 1 << n; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
				f[i][j][k] = 1e9;
	f[0][0][0] = 0;
	for(int i = 1; i < 1 << n; i++)
		for(int j = 0; j < n; j++)
			if(i >> j & 1)
				s[i] = s[i - (1 << j)] + a[j];
	for(int i = 0; i < 1 << n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if(f[i][j][k] < 1e9) {
					int C = (1 << n) - 1 - i;
					for(int S = C; S; S = (S - 1) & C)
						if(s[S] > f[i][j][k] && S >> k) {
							int nk = __builtin_ctz(S >> k << k) + 1;
							if(s[S] >= f[i + S][j + 1][nk]) continue;
							f[i + S][j + 1][nk] = s[S];
							tr[i + S][j + 1][nk] = {i, j, k};
						}
				}
	for(int num = n; num; num--)
		for(int pos = 0; pos <= n; pos++)
			if(f[(1 << n) - 1][num][pos] != 1e9) {
				calc((1 << n) - 1, num, pos);
				cout << ans.size() << endl;
				memset(ban, 0, sizeof(ban));
				for(auto it : ans) {
					cout << find(it.first) << " " << find(it.second) << endl;
					ban[it.first] = 1;
				}
				return;
			}
}
int main() {
	cin >> T;
	while(T--) solve();
	return 0;
}

/*
stupid mistakes:
	pos - 1 -> pos
	 pos  =.= 
*/