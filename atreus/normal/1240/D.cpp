#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000000039;
const int base = 300007;
const int maxn = 3e5 + 10;

ll pw[maxn];
ll answer = 0;
ll a[maxn];
map<ll, int> mp;

void divide(int L, int R){
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	divide(L, mid);
	divide(mid, R);
	ll nowhsh = 0;
	int cnt = 0;
	stack<int> s;
	for (int i = mid; i < R; i++){
		if (s.empty() or s.top() != a[i]){
			nowhsh = (nowhsh + 1ll * a[i] * pw[cnt ++] % mod) % mod;
			s.push(a[i]);
		}
		else{
			nowhsh = (nowhsh - 1ll * a[i] * pw[-- cnt] % mod + mod) % mod;
			s.pop();
		}
		mp[nowhsh] ++;
	}
	while (!s.empty())
		s.pop();
	cnt = 0;
	nowhsh = 0;
	for (int i = mid - 1; i >= L; i--){
		if (s.empty() or s.top() != a[i]){
			nowhsh = (nowhsh + 1ll * a[i] * pw[cnt ++] % mod) % mod;
			s.push(a[i]);
		}
		else{
			nowhsh = (nowhsh - 1ll * a[i] * pw[-- cnt] % mod + mod) % mod;
			s.pop();
		}
		answer += mp[nowhsh];
	}
	mp.clear();
}

int main(){
	ios_base::sync_with_stdio (false);
	pw[0] = 1;
	for (int i = 1; i < maxn; i++)
		pw[i] = 1ll * pw[i - 1] * base % mod;
	int tc;
	cin >> tc;
	while (tc --){
		answer = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		divide(0, n);
		cout << answer << endl;
	}
}