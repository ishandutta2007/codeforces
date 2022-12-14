#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 5e5 + 10;

int n, k;
string s;
int dp[maxn];
int pos[maxn], suf[maxn], cnt[maxn], b[maxn], lcp[maxn][21];
pair<int,int> a[maxn];

void radixsort(){
	for (int i = 0; i < n; i++)
		cnt[a[i].second] ++;
	for (int i = 1; i <= max(26, n); i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[-- cnt[a[i].second]] = i;
	for (int i = 0; i <= max(26, n); i++)
		cnt[i] = 0;

	for (int i = 0; i < n; i++)
		cnt[a[b[i]].first] ++;
	for (int i = 1; i <= max(26, n); i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		suf[-- cnt[a[b[i]].first]] = b[i];
	for (int i = 0; i <= max(26, n); i++)
		cnt[i] = 0;
}

void buildSA(){
	for (int i = 0; i < n; i++){
		suf[i] = i;
		pos[i] = (int)(s[i] - 'a');
	}
	for (k = 1; ; k += k){
		for (int i = 0; i < n; i++){
			a[i].first = pos[i] + 1;
			a[i].second = (i + k < n ? pos[i + k] : -1) + 1;
		}
		radixsort();
		pos[suf[0]] = 0;
		for (int i = 1; i < n; i++)
			pos[suf[i]] = pos[suf[i - 1]] + (a[suf[i - 1]] < a[suf[i]]);
		if (pos[suf[n - 1]] == n - 1)
			break;
	}
}

void buildLCP(){
	s += '#';
	int k = 0;
	for (int i = 0; i < n; i++){
		if (pos[i] == n - 1){
			k = 0;
			continue;
		}
		int j = suf[pos[i] + 1];
		while (s[i + k] == s[j + k])
			k ++;
		lcp[pos[i]][0] = k;
		if (k)
			k --;
	}
	for (int i = 1; i <= 20; i++)
		for (int j = 0; j + (1 << i) < n; j++)
			lcp[j][i] = min(lcp[j][i-1], lcp[j+(1<<(i-1))][i-1]);
}

int seg[4 * maxn];

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return max(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
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

bool ok(int i, int len){
	i = pos[i];
	int l = i, r = i;
	for (int i = 19; i >= 0; i--)
		if (r + (1 << i) < n and lcp[r][i] >= len)
			r += (1 << i);
	for (int i = 19; i >= 0; i--)
		if (l - (1 << i) >= 0 and lcp[l - (1 << i)][i] >= len)
			l -= (1 << i);
	return get(1, 0, n, l, r + 1) >= len;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	buildSA();
	buildLCP();
	dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--){
		dp[i] = dp[i + 1] + 1;
		while (dp[i] > 0 and !ok(i, dp[i] - 1) and !ok(i+1, dp[i] - 1)){
			dp[i] --;
			add(1, 0, n, pos[i + dp[i]], dp[i + dp[i]]);
		}
	}
	cout << *max_element(dp, dp + n) << '\n';
}