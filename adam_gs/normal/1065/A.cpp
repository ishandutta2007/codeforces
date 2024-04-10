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
        long long s, a, b, c;
        cin >> s >> a >> b >> c;
        s/=c;
        s+=s/a*b;
        cout << s;
        nl;
	}
}