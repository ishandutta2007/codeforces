#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 3;

int a[maxn];
int lef[20][maxn], rig[20][maxn];
int segl[20][4*maxn], segr[20][4*maxn];

int lg;

pair<int,int> get(int id, int L, int R, int l, int r, int lg){
	if (l <= L and R <= r)
		return {segl[lg][id], segr[lg][id]};
	int mid = (L + R) >> 1;
	if (r <= mid)
		return get(2*id+0, L, mid, l, r, lg);
	if (mid <= l)
		return get(2*id+1, mid, R, l, r, lg);
	auto i = get(2*id+0, L, mid, l, r, lg);
	auto j = get(2*id+1, mid, R, l, r, lg);
	return {min(i.first, j.first), max(i.second, j.second)};
}

void build(int id, int L, int R){
	if (L + 1 == R){
		segl[lg][id] = lef[lg][L];
		segr[lg][id] = rig[lg][L];
		return;
	}
	int mid = (L + R) >> 1;
	build(2*id+0, L, mid);
	build(2*id+1, mid, R);
	segl[lg][id] = min(segl[lg][2*id+0],segl[lg][2*id+1]);
	segr[lg][id] = max(segr[lg][2*id+0],segr[lg][2*id+1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1)
		return cout << 0 << endl, 0;
	for (int i = n; i < 3*n; i++)
		a[i] = a[i%n];
	for (int i = 0; i < 3*n; i++){
		lef[0][i] = max(0, i - a[i]);
		rig[0][i] = min(3*n-1, i + a[i]);
	}
	for (lg = 0; lg < 18; lg++){
		build(1, 0, 3*n);
		for (int i = 0; i < 3*n; i++){
			int L = lef[lg][i], R = rig[lg][i];
			auto it = get(1, 0, 3*n, L, R+1, lg);
			lef[lg+1][i] = it.first, rig[lg+1][i] = it.second;
		}
	}
	build(1, 0, 3*n);
	for (int i = n; i < 2*n; i++){
		int L = i, R = i;
		int answer = 0;
		for (int j = 18; j >= 0; j--){
			auto it = get(1, 0, 3*n, L, R+1, j);
			if (it.second - it.first + 1 < n)
				L = it.first, R = it.second, answer |= (1 << j);
		}
		cout << answer + 1 << ' ';
	}
	cout << '\n';
}