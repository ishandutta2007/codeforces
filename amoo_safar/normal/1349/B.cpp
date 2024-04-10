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

ll Main(){
	ll n, k;
	cin >> n >> k;
	ll fl = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == k) fl = 1;
		if(a[i] >= k) a[i] = 1;
		else a[i] = 0;
	}
	if(fl == 0) return cout << "no\n", 0;
	if(n == 1) return cout <<"yes\n", 0;
	for(int i = 0; i + 1 < n; i++){
		if(a[i] == 1 && a[i + 1] == 1){
			return cout << "yes\n", 0;
		}
	}
	for(int i = 0; i + 2 < n; i++){
		if(a[i] == 1 && a[i + 2] == 1){
			return cout << "yes\n", 0;
		}
	}
	cout << "no\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) Main();
	return 0;
}