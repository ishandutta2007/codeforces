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
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2 && y1 == y2) return cout << "0\n", 0;
	if(x1 == x2){
		cout << abs(y1 - y2) << '\n';
		return 0;
	}
	if(y1 == y2){
		cout << abs(x1 - x2) << '\n';
		return 0;
	}
	cout << abs(x1 - x2) + abs(y1 - y2) + 2 << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}