#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

const ll maxn = 4e5 + 10;
const ll inf = 1e9;

ll mxm[maxn], mnm[maxn], b[maxn], nex[maxn], pre[maxn];
ll dp[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	memset(mxm, -1, sizeof mxm);
	memset(mnm, -1, sizeof mnm);
	mnm[1] = mxm[1] = 1;
	ll maxrow = 0;
	for (ll i = 1; i <= k; i++){
		ll r, c;
		cin >> r >> c;
		maxrow = max(maxrow, r);
		mxm[r] = (mxm[r] == -1ll ? c : max(mxm[r], c));
		mnm[r] = (mnm[r] == -1ll ? c : min(mnm[r], c));
	}
	for (ll i = 0; i < q; i++)
		cin >> b[i];
	sort(b, b + q);
	ll ptr = 0;
	for (ll i = 1; i <= m; i++){
		while (ptr < q - 1 and b[ptr + 1] <= i)
			ptr ++;
		pre[i] = b[ptr];
	}
	ptr = q - 1;
	for (ll i = m; i >= 1; i--){
		while (ptr > 0 and b[ptr - 1] >= i)
			ptr --;
		nex[i] = b[ptr];
	}
	vector<ll> last;
	last.push_back(pre[mxm[1]]);
	last.push_back(nex[mxm[1]]);
	dp[pre[mxm[1]]] = abs(mxm[1] - 1) + abs(pre[mxm[1]] - mxm[1]);
	dp[nex[mxm[1]]] = abs(mxm[1] - 1) + abs(nex[mxm[1]] - mxm[1]);
	if (maxrow == 1)
		return cout << mxm[1] - 1 << endl, 0;
	for (ll r = 2; r <= n; r++){
		if (mxm[r] == -1)
			continue;
		ll fi = 2ll * n * m, se = 2ll * n * m;
		for (auto it : last){
			fi = min(fi, dp[it] + abs(it - mxm[r]) + abs(mxm[r] - mnm[r]));
			se = min(se, dp[it] + abs(it - mnm[r]) + abs(mxm[r] - mnm[r]));
		}
		if (r == maxrow)
			return cout << min(fi, se) + r - 1 << endl, 0;
		last.clear();
		dp[pre[mnm[r]]] = fi + abs(pre[mnm[r]] - mnm[r]);
		dp[nex[mnm[r]]] = fi + abs(nex[mnm[r]] - mnm[r]);
		dp[pre[mxm[r]]] = se + abs(pre[mxm[r]] - mxm[r]);
		dp[nex[mxm[r]]] = se + abs(nex[mxm[r]] - mxm[r]);
		last.push_back(pre[mnm[r]]);
		last.push_back(pre[mxm[r]]);
		last.push_back(nex[mnm[r]]);
		last.push_back(nex[mxm[r]]);
	}
}