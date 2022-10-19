#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
	int x;
	cin >> x;
	if (x==1) {
        cout << -1;
	} else {
	    x/=2;
	    x*=2;
        cout << x << " " << 2;
    }
}