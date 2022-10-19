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
        string a, b, c;
        cin >> a >> b >> c;
        bool t=true;
        for (int i = 0; i < len(a); ++i) {
            if (a[i]!=c[i] && b[i]!=c[i]) {
                t=false;
            }
        }
        if (t==true) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        nl;
    }
}