
// Dennis - Toney
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll A[N];

int Main(){
	int n; ll k;
	cin >> n >> k;
	map<ll, int> mp;
	ll S = 0 ;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		mp[A[i]] ++;
	}
	for(int i = 1; i <= n; i++){
		ll rq = A[i] - k;
		if(mp[rq])
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}