#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 25;

int cnt[(1 << 24) + 10], a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll ans = 0;
	for(int i = 0; i < Log; i++){
		memset(cnt, 0, sizeof cnt);
		int C = 0;
		for(int j = 0; j < n; j++)
			if(a[j] >> i & 1){
				C += ((n - 1) & 1);
			}
		C &= 1;
		int T = (1 << i);
		for(int j = 0; j < n; j++){
			cnt[a[j] & (T - 1)] += 1;
		}
		for(int j = T ; j >= 0; j--){
			cnt[j] += cnt[j + 1];
		}
		ll Al = 0;
		for(int j = 0; j < n; j++){
			Al += cnt[T - (a[j] & (T - 1))];
			if(2 * (a[j] & (T - 1)) >= T) Al --;
		}
		Al >>= 1;
		Al &= 1;
		C ^= Al;
		ans |= (C << i);
	}

	cout << ans << '\n';
	return 0;
}
/*
2
10000000 9999999

*/