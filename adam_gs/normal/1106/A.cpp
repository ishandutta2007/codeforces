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
    string x[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int r=0;
    for (int i = 0; i < n-2; ++i) {
        for (int j= 0; j < n-2; ++j) {
            if (x[i][j]=='X' && x[i][j+2]=='X' && x[i+1][j+1]=='X' && x[i+2][j]=='X' && x[i+2][j+2]=='X') {
                ++r;
            }
        }
    }
    cout << r;
}