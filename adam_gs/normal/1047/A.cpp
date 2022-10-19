#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
	int n;
	cin >> n;
	if (n%3==0) {
        n/=3;
        if (n%3==0) {
            cout << n-2 << " " << n+1 << " " << n+1;
        } else {
            cout << n << " " << n << " " << n;
        }
	} else if (n%3==1) {
        n/=3;
        if (n%3==0) {
            cout << n-1 << " " << n+1 << " " << n+1;
        } else if ((n+1)%3==0) {
            cout << n+2 << " " << n << " " << n-1;
        } else {
            cout << n+1 << " " << n << " " << n;
        }
	} else {
        n/=3;
        if (n%3==0) {
            cout << n+2 << " " << n+1 << " " << n-1;
        } else if ((n+2)%3==0) {
            cout << n+1 << " " << n+1 << " " << n;
        } else {
            cout << n+2 << " " << n << " " << n;
        }
	}
}