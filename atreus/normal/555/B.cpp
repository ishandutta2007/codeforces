/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;

ll b[maxn], l[maxn], r[maxn], idx[maxn];

bool cmp(int fi, int se){
	if (r[fi] != r[se])
		return r[fi] < r[se];
	return l[fi] < l[se];
}

ll ans[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	for (ll i = 1; i <= n - 1; i++){
		ll mindis = l[i + 1] - r[i];
		ll maxdis = r[i + 1] - l[i];
		l[i] = mindis, r[i] = maxdis;
		idx[i] = i;
	}
	sort(idx + 1, idx + n, cmp);
	set<pair<ll, int> > s;
	for (ll i = 1; i <= m; i++){
		cin >> b[i];
		s.insert({b[i], i});
	}
	for (ll i = 1; i <= n - 1; i++){
		auto it = s.lower_bound(make_pair(l[idx[i]], 0));
		if (it == s.end() or (*it).first > r[idx[i]])
			return cout << "No" << endl, 0;
		ans[idx[i]] = (*it).second;
		s.erase(it);
	}
	cout << "Yes" << endl;
	for (ll i = 1; i <= n - 1; i++)
		cout << ans[i] << " ";
}