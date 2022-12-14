#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

vector<int> a;
int dp[22][maxn], pd[22][maxn];
int w;
ll seg[4 * maxn];

void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] += val;
		return;
	}
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
}

ll get(int id, int L, int R, int idx){
	if (L + 1 == R)
		return seg[id];
	int mid = (L + R) >> 1;
	if (idx < mid)
		return seg[id] + get(2 * id + 0, L, mid, idx);
	return seg[id] + get(2 * id + 1, mid, R, idx);
}

void handle(int L, int R, int l, int r){
	if (L > R)
		return;
	int k = log2(r - l + 1);
	int f = dp[k][l], s = pd[k][r];
	int idx;
	if (a[f] > a[s])
		idx = f;
	else
		idx = s;
	int len = a.size();
	int lef = max(idx + 1, L);
	int rig = min(w - (len - idx) + 1, R);
	add(1, 1, w + 1, lef, rig + 1, a[idx]);
	handle(L, lef - 1, l, idx - 1);
	handle(rig + 1, R, idx + 1, r);
}

void buildRMQ(){
	int n = a.size();
	for (int i = 0; i < n; i++)
		dp[0][i] = pd[0][i] = i;
	for (int i = 1; i <= 20; i++){
		for (int j = 0; j + (1 << i) <= n; j++){
			int f = dp[i - 1][j], s = dp[i - 1][j + (1 << (i - 1))];
			if (a[f] > a[s])
				dp[i][j] = f;
			else
				dp[i][j] = s;
		}
	}
	for (int i = 1; i <= 20; i++){
		for (int j = (1 << i) - 1; j < n; j++){
			int f = pd[i - 1][j], s = pd[i - 1][j - (1 << (i - 1))];
			if (a[f] > a[s])
				pd[i][j] = f;
			else
				pd[i][j] = s;
		}
	}
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n >> w;
	for (int i = 0; i < n; i++){
		int len;
		cin >> len;
		a.resize(len);
		for (int j = 0; j < len; j++)
			cin >> a[j];
		buildRMQ();
		int l = 1, r = w;
		int mos = -1;
		for (int j = 0; j < len; j++){
			if (a[j] >= 0){
				mos = j;
				break;
			}
		}
		if (mos == -1){
			l = w - len + 1;
			r = len;
		}
		else{
			l = min(w - len + 1, mos + 1);
			for (int j = 0; j < len; j++)
				if (a[j] >= 0)
					mos = j;
			r = max(len, w - (len - mos - 1));
		}
		handle(l, r, 0, len - 1);
		a.clear();
	}
	for (int i = 1; i <= w; i++)
		cout << get(1, 1, w + 1, i) << " ";
	cout << endl;
}