#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

int N;
map <ll, ll> hor, ver;
map <pii, ll> cnt;
ll tot;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ll w, h, c;
		scanf("%lld%lld%lld", &w, &h, &c);
		tot += c;
		hor[w] += c;
		ver[h] += c;
		cnt[{w, h}] += c;
	}
}

bool check(ll a, ll b, ll c, ll d) {
	ll g1 = __gcd(a, c);
	ll g2 = __gcd(d, b);
	return a / g1 == d / g2 && c / g1 == b / g2;
}

int solve() {
	if ((ll)hor.size() * ver.size() > N)
		return 0;
	
	ll s = 0, t = 0;
	for (auto it1 : hor)
		for (auto it2 : ver) {
			s = __gcd(s, it1.second);
			t = __gcd(t, it2.second);
			if (!check(it1.second, it2.second, tot, cnt[{it1.first, it2.first}]))
				return 0;
		}
	
	tot /= __gcd(tot, t);
	
	if (s % tot)
		return 0;
	s /= tot;
	
	int sol = 0;
	for (ll i = 1; i * i <= s; i++)
		sol += 2 * !(s % i) - (i * i == s);
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}