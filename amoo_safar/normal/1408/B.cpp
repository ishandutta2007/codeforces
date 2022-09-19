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
const ld EPS = 1e-7;

ll a[N];
	
int Main(){
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(k == 1){
		for(int i = 1; i + 1 <= n; i++)
			if(a[i] != a[i + 1]){
				return cout << "-1\n", 0;
			}
		return cout << "1\n", 0;
	}
	ll cnt = 0;
	for(int i = 1; i + 1 <= n; i++)
		if(a[i] != a[i + 1])
			cnt ++;
	cout <<  max(1ll, (cnt + k - 1 - 1) / (k - 1)) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}