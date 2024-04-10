// vaziat meshki-ghermeze !
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

int a[N];

int Main(){
	int n;
	cin >> n;
	if(n % 2 == 1) return cout << "NO\n", 0;
	while(n % 2 == 0) n /= 2;
	int fl = 0;
	for(ll i = 1; i * i <= n; i ++){
		if(i * i == n) fl = 1;
	}
	cout << (fl ? "YES\n" : "NO\n");

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}