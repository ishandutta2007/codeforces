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
        a=abs(a-b);
        b=a/5;
        int r = b;
        b*=5;
        a-=b;
        if (a>2) {
            r+=2;
        } else if (a>0) {
            ++r;
        }
        cout << r;
        nl;
	}
}