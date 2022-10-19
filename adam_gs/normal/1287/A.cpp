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
        int n;
        cin >> n;
        string x;
        cin >> x;
        int ma=0;
        int p=0;
        while (p<n) {
            if (x[p]=='A') {
                break;
            }
            ++p;
        }
        for (int i = p+1; i < n; ++i) {
            if (x[i]=='A') {
                ma=max(ma, i-p);
                p=i;
            }
        }
        ma=max(ma, n-p);
        cout << max(ma-1, 0);
        nl;
    }
}