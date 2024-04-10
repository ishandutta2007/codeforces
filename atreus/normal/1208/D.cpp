#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

ll a[maxn], fen[maxn];
int p[maxn];

ll get(int idx){
	ll ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

void add(int idx, int val){
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += val;
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--){
		int lo = 0, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (1ll * mid * (mid + 1) / 2 - get(mid) <= a[i])
				lo = mid;
			else
				hi = mid;
		}
		p[i] = hi;
		add(hi, hi);
	}
	for (int i = 1; i <= n; i++)
		cout << p[i] << " \n"[i == n];
}