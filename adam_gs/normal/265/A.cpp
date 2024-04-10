#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)


int main() {
    string a, b;
    cin >> a >> b;
    int l1=0;
    int l2=0;
    while (l2<len(b)) {
        if (a[l1]==b[l2]) {
            ++l1;
        }
        ++l2;
    }
    cout << l1+1;
}