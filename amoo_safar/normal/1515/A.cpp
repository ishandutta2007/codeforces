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
	ll x;
	cin >> n >> x;
	ll s = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	int idx = -1;
	for(int i = 0; i < n; i++){
		s += a[i];
		if(s == x) idx = i;
	}
	if(idx == n - 1) cout << "NO\n";
	else {
		cout << "YES\n";
		if(idx != -1) swap(a[idx], a[idx + 1]);
		for(int i = 0; i < n; i++)
			cout << a[i] << " \n"[i == n - 1];
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}