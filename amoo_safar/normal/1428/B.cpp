// I'll Crush you !
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

int Main(){
	ll n;
	cin >> n;
	str s;
	cin >> s;
	bool f1 = true, f2 = true;
	for(auto c : s){
		if(c == '>') f1 = false;
		if(c == '<') f2 = false;
	}
	if(f1 || f2) return cout << n << "\n", 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		char nx = s[i];
		char pr = s[(i + n - 1) % n];
		if(nx == '-' || pr == '-') ans ++;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}