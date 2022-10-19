#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
    int n, s;
    cin >> n >> s;
    if (s%n==0) {
        cout << s/n;
    } else {
        cout << s/n+1;
    }
}