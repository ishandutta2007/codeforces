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
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Main(){
	ll n;
	cin >> n;
	ll v;
	bool fl = false;
	for(int i = 1; i <= n; i++){
		cin >> v;
		ll j = i + 1;
		while(j > 0){
			if(v % j == 0) j--;
			else break;
		}
		if(j == 0) fl = true;
		else {
			int d = (i + 1) - j;
			if(d > i - 1) fl = true;
		}
	}
	cout << (fl ? "NO" : "YES") << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}