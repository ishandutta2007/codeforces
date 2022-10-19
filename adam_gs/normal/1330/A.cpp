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
        int n, m;
        cin >> n >> m;
        int tab[200];
        for (int i = 0; i < 200; ++i) {
            tab[i]=0;
        }
        while (n--) {
            int a;
            cin >> a;
            tab[a-1]=1;
        }
        int l=0;
        while (m>0) {
            if (tab[l]==0) {
                --m;
            }
            ++l;
        }
        while (tab[l]==1) {
            ++l;
        }
        cout << l;
        nl;
	}
}