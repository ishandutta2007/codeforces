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
    cout << (n*n+1)/2;
    nl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i+j)%2==0) {
                cout << 'C';
            } else {
                cout << '.';
            }
        }
        nl;
    }
}