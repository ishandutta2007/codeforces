#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
    int n, m;
    cin >> n >> m;
    int r = 0;
    int l = 0;
    for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        int s = 0;
        for (int j = 0; j< n; ++j) {
            s+=x[j]-'0';
        }
        if (s<n) {
            ++l;
            r=max(r, l);
        } else {
            l=0;
        }
    }
    cout << r;
}