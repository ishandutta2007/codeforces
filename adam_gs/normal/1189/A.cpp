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
    string x;
    cin >> x;
    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum+=x[i]-'0';
    }
    if (sum==n/2 && n%2==0) {
        cout << 2;
        nl;
        for (int i = 0; i < n-1; ++i) {
            cout << x[i];
        }
        cout << " " << lst(x);
    } else {
        cout << 1;
        nl;
        cout << x;
    }
}