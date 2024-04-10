#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
	int t;
	tests(t) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (2*b<c) {
            cout << a*b;
        } else {
            long long p = a/2;
            p*=2;
            p=c*p/2+(a-p)*b;
            cout << p;
        }
        nl;
	}
}