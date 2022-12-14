#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 500;

ll t[maxn], a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, K, b, c;
	cin >> n >> K >> b >> c;
	for (int i = 0; i < n; i++){
		cin >> t[i];
		t[i] += 1000000000;
	}
	sort(t, t + n);
	b = min(b, 5 * c);
	ll answer = (1ll << 60);
	for (int i = 0; i < 5; i++){
		multiset<ll> s;
		s.clear();
		ll lazy = 0, sum = 0;
		for (int j = 0; j < n; j++){
			ll k = i - t[j] % 5;
			if (k < 0)
				k += 5;
			a[j] = t[j] + k;
			ll cost = k * c;

			if (j > 0){
				ll m = (a[j] - a[j - 1]) / 5;
				lazy += m * b;
			}
			s.insert(cost - lazy);
			sum += cost - lazy;
			if (s.size() > K){
				auto it = s.end();
				it --;
				sum -= *it;
				s.erase(it);
			}
			if (s.size() == K){
				answer = min(answer, sum + K * lazy);
			}
		}
	}
	cout << answer << endl;
}