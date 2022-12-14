#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;

bool ask(ll l, ll r){
	cout << l << " " << r << endl;
	string ret;
	cin >> ret;
	if (ret == "Bad")
		exit(0);
	if (ret == "Yes" and l == r)
		exit(0);
	return ret == "Yes";
}

int main(){
	ios_base::sync_with_stdio(false); 
	srand(time(NULL));
	cin >> n >> k;
	ll lo = 1, hi = n;
	while (true){
		ll len = hi - lo + 1;
		ll mid = (hi + lo) >> 1;
		if (len > 4 * k + 3){
			if (ask(lo, mid))
				hi = mid;
			else
				lo = mid + 1;
		}
		else{
			ll x = rng() % len;
			if (ask(lo + x, lo + x)) throw;
		}
		hi = min(hi + k, n);
		lo = max(lo - k, 1ll);
	}
}