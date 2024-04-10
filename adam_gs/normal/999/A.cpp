#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]

int main() {
    int n, m;
    cin >> n >> m;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int p=0;
    int k=n-1;
    int r=0;
    while (p<=k) {
        if (tab[p]<=m) {
            ++p;
            ++r;
        } else if (tab[k]<=m) {
            --k;
            ++r;
        } else {
            break;
        }
    }
    cout << r;
}