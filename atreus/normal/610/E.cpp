#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int n, m, k;
string s;
int seg[4 * maxn][10][10], lzy[4 * maxn];
int firs[4 * maxn], last[4 * maxn];

void shift(int, int, int);

void change(int id, int L, int R, int l, int r, int x){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		firs[id] = last[id] = x;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				seg[id][i][j] = 0;
		seg[id][x][x] = R - L - 1;
		lzy[id] = x;
		return;
	}
	shift(id, L, R);
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, l, r, x);
	change(2 * id + 1, mid, R, l, r, x);
	firs[id] = firs[2 * id + 0];
	last[id] = last[2 * id + 1];
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			seg[id][i][j] = seg[2 * id + 0][i][j] + seg[2 * id + 1][i][j];
	seg[id][last[2 * id + 0]][firs[2 * id + 1]] ++;
}

void shift(int id, int L, int R){
	if (lzy[id] == -1)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lzy[id]);
	change(2 * id + 1, mid, R, mid, R, lzy[id]);
	lzy[id] = -1;
}

void build(int id, int L, int R){
	lzy[id] = -1;
	if (L + 1 == R){
		last[id] = firs[id] = (int)(s[L] - 'a');
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	firs[id] = firs[2 * id + 0];
	last[id] = last[2 * id + 1];
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			seg[id][i][j] = seg[2 * id + 0][i][j] + seg[2 * id + 1][i][j];
	seg[id][last[2 * id + 0]][firs[2 * id + 1]] ++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	cin >> s;
	build(1, 0, n);
	while (m --){
		int type;
		cin >> type;
		if (type == 1){
			int l, r;
			char c;
			cin >> l >> r >> c;
			int x = (int)c - 'a';
			l --;
			change(1, 0, n, l, r, x);
		}
		else{
			string s;
			cin >> s;
			int answer = 0;
			for (int i = 0; i < k; i++){
				for (int j = i; j >= 0; j--){
					int fi = (int)(s[i] - 'a');
					int se = (int)(s[j] - 'a');
					answer += seg[1][fi][se];
				}
			}
			cout << ++ answer << '\n';
		}
	}
}