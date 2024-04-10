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
        int a, b, c;
        cin >> a >> b >> c;
        int r=3*(min(b, c/2));
        b-=min(b, c/2);
        r+=3*min(a, b/2);
        cout << r;
        nl;
    }
}