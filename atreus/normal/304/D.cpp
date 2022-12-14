#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int n, m, x, y;

int main(){
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> n >> m >> x >> y >> a >> b;
	int g = gcd(a,b);
	a /= g, b /= g;
	int A = a, B = b;
	while (A + a <= n and B + b <= m)
		A += a, B += b;
	int x1 = 0, y1 = 0, x2 = A, y2 = B;
	ld cenx = .5*x2, ceny = .5*y2;
	while (cenx+1 <= x and x2 < n)
		x1 ++, cenx ++, x2 ++;
	while (ceny+1 <= y and y2 < m)
		y1 ++, ceny ++, y2 ++;
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}