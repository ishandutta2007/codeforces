#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 3;
const int mod = 1e6 + 7;

int a[maxn], last[maxn], nex[maxn], pre[maxn], dp[maxn], pd[maxn], PD[maxn];
int seg[4 * maxn];

int get(int id, int L, int R, int l, int r, int mn){
	if (r <= L or R <= l or seg[id] <= mn)
		return -1;
	if (L + 1 == R)
		return L;
	int mid = (L + R) >> 1;
	int ret = get(2 * id + 1, mid, R, l, r, mn);
	if (ret != -1)
		return ret;
	return get(2 * id + 0, L, mid, l, r, mn);
}

void add(int id, int L, int R, int idx, int val){
	if (idx < L or R <= idx)
		return;
	if (L + 1 == R){
		seg[id] = val;
		return;
	}
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, idx, val);
	add(2 * id + 1, mid, R, idx, val);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> cmp;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cmp.push_back(a[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
	
	memset(last, -1, sizeof last);
	for (int i = n; i >= 1; i--){
		nex[i] = last[a[i]];
		last[a[i]] = i;
	}

	memset(last, -1, sizeof last);
	for (int i = 1; i <= n; i++){
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}

	for (int i = 1; i <= n; i++){
		int now = i, cnt = 0;
		while (pre[now] != -1 and cnt < 3){
			now = pre[now];
			cnt ++;
		}
		if (cnt == 3){
			pd[i] = now;
			PD[i] = a[i];
		}
	}

	for (int i = 1; i <= n; i++){
		if (pre[i] != -1)
			add(1, 1, n + 1, pre[i], i);
		if (pre[i] <= 1)
			continue;
		int idx = get(1, 1, n + 1, 1, pre[i], pre[i]);
		if (idx == -1)
			continue;
		if (pd[i] < idx){
			pd[i] = max(pd[i], idx);
			PD[i] = a[idx];
		}
	}
	for (int i = 1; i <= n; i++){
		if (pd[i] != 0)
			dp[i] = dp[pd[i] - 1] + 1;
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << 4 * dp[n] << '\n';
	vector<int> v;
	while (n >= 1){
		if (dp[n] == dp[n - 1]){
			n --;
			continue;
		}
		v.push_back(a[n]);
		v.push_back(PD[n]);
		v.push_back(a[n]);
		v.push_back(PD[n]);
		n = pd[n] - 1;
	}
	reverse(v.begin(), v.end());
	for (auto it : v)
		cout << cmp[it - 1] << " ";
	cout << '\n';
}