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
	int tab[n];
	for (int i = 0; i < n; ++i) {
        cin >> tab[i];
	}
	sort(tab, tab+n);
	int r=0;
	int p=0;
	while (p<s) {
        p+=tab[n-r-1];
        ++r;
	}
	cout << r;
}