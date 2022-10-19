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
        int tab[n];
        for (int i = 0; i < n; ++i) {
            cin >> tab[i];
        }
        sort(tab, tab+n);
        for (int i = 0; i < n; ++i) {
            if (tab[i]>=n-i) {
                cout << n-i;
                nl;
                break;
            }
        }
	}
}