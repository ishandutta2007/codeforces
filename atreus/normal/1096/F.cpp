#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int mod = 998244353;
const int maxn = 2e5 + 100;

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int a[maxn], mark[maxn];

int fen[maxn];

int n;

void add(int x){
	for (; x <= n; x += x & -x)
		fen[x] ++;
}

int get(int x){
	int ret = 0;
	for (; x; x -= x & -x)
		ret += fen[x];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mark[a[i]] = 1;
	}

	vector <int> v;
	for (int i = 1; i <= n; i++)
		if (mark[i] == 0)
			v.push_back(i);

	if (v.empty()){
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			ans += i - 1 - get(a[i]);
			add(a[i]);
		}
		cout << ans % mod << endl;
		return 0;
	}

	ll P = 0, Q = v.size();
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] != -1){
			P = (P + ((i - cnt - 1) - get(a[i])) * Q) % mod;
			add(a[i]);
			int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			P = (P + cnt * (Q - idx)) % mod;
			P = (P + (Q - cnt) * idx) % mod;
		}
		else{
			cnt ++;
		}
	}
	P = (P + Q * Q % mod * (Q - 1) % mod * power(4, mod - 2)) % mod;
	cout << P * power(Q, mod - 2) % mod << endl;
}