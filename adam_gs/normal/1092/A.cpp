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
        int a, b;
        cin >> a >> b;
        int l=0;
        for (int i = 0; i < a; ++i) {
            char p='a'+l;
            cout << p;
            ++l;
            l%=b;
        }
        nl;
    }
}