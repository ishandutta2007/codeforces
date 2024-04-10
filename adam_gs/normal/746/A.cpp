#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	b/=2;
	c/=4;
	cout << min(a, min(b, c))*7;
}