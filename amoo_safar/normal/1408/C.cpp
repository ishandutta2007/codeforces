// That's How much we have in common
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
const ld EPS = 1e-7;

ll a[N];
void Main(){
	ll n;
	ld l;
	cin >> n >> l;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ld p1 = 0, p2 = l, s1 = 1, s2 = 1;
	ll P1 = 1, P2 = n;
	ld ans = 0;

	for(int i = 0; P1 <= P2; i++){
	//err << P1 << ' ' << P2 << '\n';
		ld t = min((a[P1]-p1) / s1, (p2 - a[P2]) / s2);
		ans += t;

		p1 += s1 * t;
		p2 -= s2 * t;
		if(abs(a[P1] - p1) <= EPS){
			s1 ++;
			P1 ++;
		}
		
		if(abs(a[P2] - p2) <= EPS){
			s2 ++;
			P2 --;
		}
	}
	ans += (p2 - p1) / (s1 + s2);
	cout << fixed << setprecision(16) << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}