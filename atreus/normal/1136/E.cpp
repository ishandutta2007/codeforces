#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const ll maxn = 1e5 + 10;
const ll inf = 1e9;

ll n, a[maxn], k[maxn];

pair<pair<ll, ll>, ll> seg[4 * maxn];

pair<pair<ll, ll>, ll> get(ll id, ll L, ll R, ll idx){
	if (L + 1 == R)
		return seg[id];
	ll mid = (L + R) >> 1;
	if (idx < mid)
		return max(seg[id], get(2 * id + 0, L, mid, idx));
	else
		return max(seg[id], get(2 * id + 1, mid, R, idx));
}

ll Time = 1;
void change(ll id, ll L, ll R, ll l, ll r, pair<ll,ll> x){
	Time += (id == 1);
	if (L == l and R == r){
		seg[id] = {{Time, x.first}, x.second};
		return;
	}
	ll mid = (L + R) >> 1;
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), x);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, x);
}

ll Sum[4 * maxn], Laz[4 * maxn];

void propagate(ll, ll, ll);

ll sum(ll id, ll L, ll R, ll l, ll r){
	if (L == l and R == r)
		return Sum[id];
	propagate(id, L, R);
	ll mid = (L + R) >> 1;
	ll ret = 0;
	if (l < mid)
		ret += sum(2 * id + 0, L, mid, l, min(mid, r));
	if (mid < r)
		ret += sum(2 * id + 1, mid, R, max(l, mid), r);
	return ret;
}

void add(ll id, ll L, ll R, ll l, ll r, ll val){
	if (L == l and R == r){
		Sum[id] += 1ll * (R - L) * val;
		Laz[id] += val;
		return;
	}
	propagate(id, L, R);
	ll mid = (L + R) >> 1;
	if (l < mid)
		add(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		add(2 * id + 1, mid, R, max(l, mid), r, val);
	Sum[id] = Sum[2 * id + 0] + Sum[2 * id + 1];
}

void propagate(ll id, ll L, ll R){
	if (Laz[id] == 0)
		return;
	ll mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, Laz[id]);
	add(2 * id + 1, mid, R, mid, R, Laz[id]);
	Laz[id] = 0;
}	

void add(ll idx, ll val){
	if (val == 0)
		return;
	ll pre = get(1, 1, n + 1, idx).first.second;
	ll nex = get(1, 1, n + 1, idx).second;
	if (pre < idx){
		change(1, 1, n + 1, pre, idx, {pre, idx - 1});
		change(1, 1, n + 1, idx, nex + 1, {idx, nex});
	}
	add(1, 1, n + 1, idx, nex + 1, val);
	if (nex == n)
		return;
	ll innex = sum(1, 1, n + 1, nex, nex + 1), innexnex = sum(1, 1, n + 1, nex + 1, nex + 2);
	if (innex + k[nex] > innexnex)
		add(nex + 1, innex + k[nex] - innexnex);
	else
		return;
	nex = get(1, 1, n + 1, nex + 1).second;
	change(1, 1, n + 1, idx, nex + 1, {idx, nex});
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
		change(1, 1, n + 1, i, i + 1, {i, i});
		add(1, 1, n + 1, i, i + 1, a[i]);
	}
	for (ll i = 1; i < n; i++)
		cin >> k[i];
	ll m;
	cin >> m;
	while (m --){
		char type;
		cin >> type;
		if (type == '+'){
			ll idx, x;
			cin >> idx >> x;
			add(idx, x);
		}
		else{
			ll l, r;
			cin >> l >> r;
			cout << sum(1, 1, n + 1, l, r + 1) << endl;
		}
	}
}