#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]

int main() {
    int a, b;
    cin >> a >> b;
    int w=0, d=0, l=0;
    for (int i = 1; i <=6; ++i) {
        if (abs(a-i)<abs(b-i)) {
            ++w;
        } else if (abs(a-i)>abs(b-i)) {
            ++l;
        } else {
            ++d;
        }
    }
    cout << w << " " << d << " " << l;
}