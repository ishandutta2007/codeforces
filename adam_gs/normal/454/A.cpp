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
	for (int i = 0; i < (n+1)/2; ++i) {
        for (int j= 0; j < n; ++j) {
            if (abs(j-n/2)<=i) {
                cout << "D";
            } else {
                cout << "*";
            }
        }
        nl;
	}
	for (int i = 0; i<n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j>i && j<n-i-1) {
                cout << "D";
            } else {
                cout << "*";
            }
        }
        nl;
	}
}