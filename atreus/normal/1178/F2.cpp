#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000 + 10;
const int mod = 998244353;
const int maxm = 1e6 + 10;

ll dp[maxn][maxn];
int a[maxm], mnmidx[maxn], mxmidx[maxn];
vector<int> v[maxn];

int fen[maxm];
void add(int idx){
	for (; idx < maxm; idx += idx & -idx)
		fen[idx] ++;
}

int get(int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

int get(int l, int r){
	return r - l + 1 - (get(r) - get(l - 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	for (int i = n; i >= 1; i--){
		int lef = v[i][0], rig = v[i].back();
		if (get(lef, rig) != v[i].size())
			return cout << 0 << endl, 0;
		for (auto it : v[i])
			add(it);
	}
	vector<int> newa;
	for (int i = 1; i <= m; i++)
		if (i == 1 or a[i] != a[i - 1])
			newa.push_back(a[i]);
	m = newa.size();
	for (int i = 1; i <= m; i++)
		a[i] = newa[i - 1];
	for (int i = 1; i <= n; i++)
		v[i].clear();
	for (int i = 1; i <= m; i++)
		v[a[i]].push_back(i);
	assert(m <= 2000);
	for (int len = 0; len <= m; len++){
		for (int l = 1; l + len - 1 <= m; l++){
			int r = l + len - 1;
			if (len == 0){
				dp[l][r] = 1;
				continue;
			}
			if (len == 1){
				if (v[a[l]].size() == 1)
					dp[l][r] = 1;
				continue;
			}
			bool found = 0;
			for (int x = l; x <= r; x++)
				if (v[a[x]][0] < l or v[a[x]].back() > r)
					found = 1;
			if (found){
				continue;
			}
			int mnm = l;
			for (int x = l; x <= r; x++)
				if (a[x] < a[mnm])
					mnm = x;
			int minidx = mnm, maxidx = mnm;
			for (int x = mnm; x <= r; x++)
				if (a[x] == a[mnm])
					maxidx = x;
			ll now = 1;
			int last = mnm;
			for (int x = minidx + 1; x <= r; x++){
				if (a[x] == a[mnm]){
					now = 1ll * now * dp[last + 1][x - 1] % mod;
					last = x;
				}
			}

			ll presum = (1ll + (minidx > l)) * dp[l][minidx - 1] % mod, sufsum = (1ll + (maxidx < r)) * dp[maxidx + 1][r] % mod;
			for (int x = l; x < minidx - 1; x++)
				presum = (presum + 1ll * dp[l][x] * dp[x + 1][minidx - 1]) % mod;
			for (int x = maxidx + 1; x < r; x++)
				sufsum = (sufsum + 1ll * dp[maxidx + 1][x] * dp[x + 1][r]) % mod;
			dp[l][r] = 1ll * presum * sufsum % mod * now % mod;
//			cout << l << " " << r << " -> " << presum << " " << sufsum << " " << now << " -> " << dp[l][r] << endl;
		}
	}
	cout << dp[1][m] << endl;
}