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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

// int lx = 2, rx = 4, ly = 3, ry = 5;

int Ask(int i, int j){
	cout << "? " << i << ' ' << j << endl;
	int res;
	// int res = abs(i - lx) + abs(j - ly);
	// for(int i2 = lx; i2 <= rx; i2++)
		// for(int j2 = ly; j2 <= ry; j2 ++)
			// res = min(res, abs(i - i2) + abs(j - j2));
	cin >> res;
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n = 1000000000;
	int d = Ask(n, 1);
	int L = 1, R = n;
	while(L + 1 < R){
		int mid = (L + R) >> 1;
		if(Ask(n, mid) == (d + 1) - mid) L = mid;
		else R = mid;
	}
	int x = n - (d - (L - 1)), y = L;
	int Y = Ask(x, n);
	int y2 = n - Y;
	int X = Ask(1, y);
	int x2 = X + 1;
	cout << "! " << x2 << ' ' << y << ' ' << x << ' ' << y2 << endl;
	return 0;
}