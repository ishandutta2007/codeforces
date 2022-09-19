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
	ll m, r;
	cin >> m >> r;
	ld A = sqrt(r * r * 2);
	
	ld ans = 0;
	for(ll i = 1; i <= m; i++){
		if(i != 1) ans += r + r + A;
		if(i > 2){
			ans += r*(i - 2)*(i - 1) + 2*A*(i - 2);
		}
	}
	ans *= 2;
	ans += m*2*r;
	cout << fixed << setprecision(16) << (ans)/(m * m) << '\n';
	return 0;
}