#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

vector <int> prime;

ll power(ll a, ll b){
	if (b == 0)
		return 1;
	ll ret = power(a, b / 2);
	ret = ret * ret % mod;
	if (b & 1)
		ret = ret * a % mod;
	return ret;
}

bool isprime(int x){
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	for (int i = 2; i <= 70; i++){
		if (isprime(i)){
			prime.push_back(i);
		}
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		for (int j = 0; j < 19; j++){
			int cnt = 0;
			while (x % prime[j] == 0){
				x /= prime[j];
				cnt ^= 1;
			}
			a[i] += cnt * (1 << j);
		}
	}

	set <int> s;
	s.insert(0);
	for (int i = 1; i <= n; i++){
		if (s.find(a[i]) == s.end()){
			vector <int> tmp;
			for (auto it : s)
				tmp.push_back(it ^ a[i]);
			for (auto it : tmp)
				s.insert(it);
		}
	}
	cout << (power(2, n - log2(s.size())) - 1 + mod) % mod << endl;
}