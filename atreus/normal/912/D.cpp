#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <iomanip>
#define F first
#define S second
#define MP make_pair
#define Ins insert
using namespace std;
typedef long long ll;
typedef long double ld;

set <pair <ll, ll> > mark;
set <pair <ll, pair <ll, ll> > > s;
ll n, m, k, r;

ll cal(ll x, ll y){
	if (x <= 0 || x > n || y <= 0 || y > m)
		return (1ll << 63);
	return min (min (x, n - x + 1), min (r, n - r + 1)) * min (1ll * min (y, m - y + 1), 1ll * min (r, m - r + 1));
}

int main (){
	cin >> n >> m >> r >> k;
	pair <ll, ll> O = MP((n + 1) / 2, (m + 1) / 2);
	s.Ins(MP(cal(O.F, O.S), O));
	mark.Ins(O);
	ld num = 0;
	for (int _ = 1; _ <= k; _ ++){
		auto it = s.end();
		it --;
		ll x = (*it).S.F;
		ll y = (*it).S.S;
		num += (*it).F;
		if (mark.find(MP(x, y - 1)) == mark.end()){
			mark.Ins(MP(x, y - 1));
			s.Ins(MP(cal(x, y - 1), MP(x, y - 1)));
		}
		if (mark.find(MP(x - 1, y)) == mark.end()){
			mark.Ins(MP(x - 1, y));
			s.Ins(MP(cal(x - 1, y), MP(x - 1, y)));
		}
		if (mark.find(MP(x, y + 1)) == mark.end()){
			mark.Ins(MP(x, y + 1));
			s.Ins(MP(cal(x, y + 1), MP(x, y + 1)));
		}
		if (mark.find(MP(x + 1, y)) == mark.end()){
			mark.Ins(MP(x + 1, y));
			s.Ins(MP(cal(x + 1, y), MP(x + 1, y)));
		}
		s.erase(*it);
	}
	cout << fixed << setprecision(9) << num / ((n - r + 1) * (m - r + 1)) << endl;
}