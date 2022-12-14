#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

struct sportman{
	int lef;
	int rig;
	int idx;
	bool operator < (sportman other) const{
		if (rig != other.rig)
			return rig < other.rig;
		return lef < other.lef;
	}
} a[maxn];

int seg[4 * maxn];

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l or seg[id] == R - L)
		return -1;
	if (L + 1 == R)
		return L;
	int mid = (L + R) >> 1;
	int ret = get(2 * id + 0, L, mid, l, r);
	if (ret != -1)
		return ret;
	return get(2 * id + 1, mid, R, l, r);
}

void add(int id, int L, int R, int idx){
	if (idx < L or R <= idx)
		return;
	seg[id] ++;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, idx);
	add(2 * id + 1, mid, R, idx);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		a[i].idx = i;
		a[i].lef = n - y + 1;
		a[i].rig = x;
	}
	sort(a + 1, a + m + 1);
	vector<int> answer;
	for (int i = 1; i <= m; i++){
		int l = a[i].lef, r = a[i].rig;
		int k = get(1, 1, n + 1, l, r + 1);
		if (k == -1)
			continue;
		add(1, 1, n + 1, k);
		answer.push_back(a[i].idx);
	}
	cout << answer.size() << endl;
	for (auto it : answer)
		cout << it << " ";
	cout << endl;
}