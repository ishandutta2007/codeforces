#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
const ll inf = 1e18 + 10;

ll a[maxn], b[maxn], t[maxn];
vector<ll> add[2 * maxn], del[2 * maxn];
ll mint[2 * maxn];
vector<ll> cmp;
ll seg[8 * maxn];

ll getmin(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return inf;
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return min(getmin(2 * id + 0, L, mid, l, r), getmin(2 * id + 1, mid, R, l, r));
}

void build(int id, int L, int R){
	if (L + 1 == R){
		if (mint[L] == -1)
			seg[id] = inf;
		else
			seg[id] = cmp[L] + mint[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> t[i];
		cmp.push_back(a[i]);
		cmp.push_back(b[i] - t[i] + 1);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 0; i < n; i++){
		a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin();
		int B = lower_bound(cmp.begin(), cmp.end(), b[i] - t[i] + 1) - cmp.begin();
		add[a[i]].push_back(t[i]);
		del[B].push_back(t[i]);
	}
	n = cmp.size();
	multiset<ll> s;
	for (int i = 0; i < n; i++){
		for (auto it : add[i])
			s.insert(it);
		for (auto it : del[i])
			s.erase(s.find(it));

		if (!s.empty())
			mint[i] = *s.begin();
		else
			mint[i] = -1;
	}
	build(1, 0, n);
//	for (int i = 0; i < n; i++)
//		cout << cmp[i] << " ";
//	cout << endl;
	ll answer = 0;
	ll now = 0;
	for (int i = 0; i < n - 1; i++){
		if (mint[i] == -1 or now >= cmp[i + 1])
			continue;

		now = max(now, cmp[i]);
		ll len = cmp[i + 1] - now;
		
//		cout << now << " : " << (len / mint[i]) * mint[i] << endl;

		answer += len / mint[i];
		now += 1ll * (len / mint[i]) * mint[i];
		
		if (now >= cmp[i + 1])
			continue;
		
		int lo = i + 1, hi = n;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (now + mint[i] >= cmp[mid])
				lo = mid;
			else
				hi = mid;
		}
		if (now + mint[i] <= getmin(1, 0, n, i + 1, hi)){
			answer ++;
			now += mint[i];
		}
	}
	cout << answer << endl;
}