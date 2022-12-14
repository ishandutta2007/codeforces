#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 37;

int mx, my, myx, myy, dx, dy;

map <char, int> cop, mp, mpy, mpx;
int len;

bool stillnot () {
	cop['L'] = mp['L'], cop['R'] = mp['R'], cop['U'] = mp['U'], cop['D'] = mp['D'];
	myx = mx, myy = my;
	myx -= mpx['L'] * mp['L'] + mpx['R'] * mp['R'];
	myy -= mpy['U'] * mp['U'] + mpy['D'] * mp['D'];
	int cnt = len;
	cnt -= abs (dx - myx);
	cnt -= abs (dy - myy);
	if (cnt >= 0 and cnt % 2 == 0)
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	cin >> dx >> dy;
	mpx['R'] = 1, mpx['L'] = -1, mpy['U'] = 1, mpy['D'] = -1;
	for (int i = 0; i < n; i++) {
		mx += mpx[s[i]];
		my += mpy[s[i]];
	}
	if (mx == dx and my == dy)
		return cout << 0 << endl, 0;
	int ptr = 0;
	mp[s[0]] = 1;
	int ans = 10000000;
	len = 1;
	for (int i = 0; i < n; i++) {
		if (ptr == i - 1) {
			mp[s[i]] ++;
			len ++;
			ptr = i;
		}
		while (!stillnot() and ptr < n - 1) {
			ptr ++;
			mp[s[ptr]] ++;
			len ++;
		}
		if (stillnot())
			ans = min (ans, ptr - i + 1);
		mp[s[i]] --;
		len --;
	}
	if (ans == 10000000)
		ans = -1;
	cout << ans << endl;
}