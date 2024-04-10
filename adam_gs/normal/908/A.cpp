#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
    string x;
    cin >> x;
    int r = 0;
    for (int i = 0; i < len(x); ++i) {
        if (x[i]=='1' || x[i]=='3' || x[i]=='5' || x[i]=='7' || x[i]=='9' || x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u') {
            ++r;
        }
    }
    cout << r;
}