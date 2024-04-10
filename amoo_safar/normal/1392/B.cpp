// That's How much we have in common
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	ll n, k;
	for(int i = 1; i <= T; i++){
		cin >> n >> k;
		if(k >= 3){
			if(k & 1) k = 3;
			else k = 2;
		}
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		for(int x = 0; x < k; x++){
			ll d = *max_element(a, a + n);
			for(int j = 0; j <n; j++) a[j] = d - a[j];
		}
		for(int j = 0; j < n; j++) cout << a[j] << ' ';
		cout << '\n';
	}
	return 0;
}