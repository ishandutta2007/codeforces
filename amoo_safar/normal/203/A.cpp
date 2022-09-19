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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x, t, a, b, ta, tb;
	cin >> x >> t >> a >> b >> ta >> tb;
	for(int i = 0; i < t; i++)
		for(int j = 0; j < t; j++)
			if(x == a - i*ta + b - j*tb) return cout << "YES\n", 0;
	for(int i = 0; i < t; i++)
		if(x == a - i*ta) return cout << "YES\n", 0;
	for(int i = 0; i < t; i++)
		if(x == b - i*tb) return cout << "YES\n", 0;
	if(x == 0) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}