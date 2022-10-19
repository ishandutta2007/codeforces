#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
    int t;
    bool r=false;
    tests(t) {
        string x;
        cin >> x;
        int a, b;
        cin >> a >> b;
        if (a>=2400 && b>a) {
            r=true;
        }
    }
    if (r==true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}