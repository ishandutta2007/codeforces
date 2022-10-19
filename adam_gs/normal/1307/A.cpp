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
        int n, d;
        cin >> n >> d;
        int tab[n];
        for (int i = 0; i < n; ++i) {
            cin >> tab[i];
        }
        int l=1;
        while (d>0 && l<n) {
            if (tab[l]>0) {
                if (d>=l) {
                    d-=l;
                    ++tab[0];
                    --tab[l];
                } else {
                    break;
                }
            } else {
                ++l;
            }
        }
        cout << tab[0];
        nl;
    }
}