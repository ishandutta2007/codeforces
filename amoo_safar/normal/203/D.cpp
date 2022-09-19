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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ld Solve(ld l, ld x, ld v, ld T){
	ll fl = 0;
	x += T * v;
	while(x < 0){
		x += l;
		fl ^= 1;
	}
	while(x > l){
		x -= l;
		fl ^= 1;
	}
	if(fl) x = l - x;
	return x;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ld a, b, m, vx, vy, vz;
	cin >> a >> b >> m >> vx >> vy >> vz;
	cout << fixed << setprecision(16) << Solve(a, a / 2, vx, m / abs(vy)) << " " << Solve(b, 0, vz, m / abs(vy));
	return 0;
}