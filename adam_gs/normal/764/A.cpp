#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int euk(int a, int b) {
    if (a==0) {
        return b;
    } else {
        return euk(b%a, a);
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int s=a*b/euk(a, b);
    int i = s;
    int r = 0;
    while (i<=c) {
        ++r;
        i+=s;
    }
    cout << r;
}