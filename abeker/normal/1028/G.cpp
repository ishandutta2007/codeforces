#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const ll MAX = 10004205361450474;
const ll MAGIC = 204761410474;
const int N = 1e4;

unordered_map <ll, ll> dp[10];

pii query(ll lo, ll hi, vector <ll> v) {
	printf("%d\n", v.size());
	for (auto it : v)
		printf("%lld ", it);
	puts("");
	fflush(stdout);
	
	int ans;
	scanf("%d", &ans);
	
	if (ans < 0)
		exit(0);
	if (!ans)
		return {lo, v[0] - 1};
	if (ans == v.size())
		return {v.back() + 1, hi};
	return {v[ans - 1] + 1, v[ans] - 1};
}

void finish(ll lo, ll hi) {
	ll len = hi - lo + 1;
	vector <ll> v;
	if (len <= N) {
		for (ll i = lo; i <= hi; i++)
			v.push_back(i);
		query(lo, hi, v);
	}
	ll curr = lo - 1;
	ll rem = (len - N) % (N + 1);
	for (int i = 0; i < N + 1; i++) {
		if (i)
			v.push_back(curr);
		curr += 1 + (len - N) / (N + 1) + (i < rem);
	}
	
	pii tmp = query(lo, hi, v);
	
	finish(tmp.first, tmp.second);	
}

ll f(ll l, int k) {
	ll &ref = dp[k][l];
	if (ref)
		return ref;
	if (k == 1)
		return ref = l + min(l, (ll)N) - 1;
	ll curr = l - 1;
	for (ll i = 0; i <= min(l, (ll)N); i++) {
		if (k == 2 && curr >= N) {
			curr += (min(l, (ll)N) - i + 1) * (N + 1);
			break;
		}
		curr = f(curr + 1, k - 1) + 1;
	}
	return ref = curr - 1;
}

void search(ll l, ll r, int k) {
	vector <ll> v;
	if (k == 1) {
		for (ll i = l; i <= r; i++)
			v.push_back(i);
		query(l, r, v);
	}
	
	ll curr = l - 1;
	for (ll i = 0; i <= min(l, (ll)N); i++) {
		curr = f(curr + 1, k - 1) + 1;
		v.push_back(curr);
	}
	v.pop_back();
	
	pii tmp = query(l, r, v);
	
	search(tmp.first, tmp.second, k - 1);
}

int main() {
	pii tmp = query(1, MAX, {MAGIC});
	
	if (tmp.first > 1) 
		finish(MAGIC + 1, MAX);
	
	search(1, MAGIC, 4);
	
	return 0;
}