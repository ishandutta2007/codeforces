#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        n--;
        lli a = n / 3, b = n % 3;
        if (a == 0) {
            cout << n + 1 << endl;
            continue;
        }
        lli count = 0, now = 1;
        while (count + now <= a) {
            count += now;
            now *= 4;
        }
        lli ans = now + a - count;
        lli c = ans - now;
        vector <int> pre;
        lli tmp = c;
        while (tmp > 0) {
        	pre.pb(tmp % 4);
        	tmp /= 4;
		}
		if (b == 1) {
			for (int &i : pre) {
				if (i == 0) i = 0;
				else if (i == 1) i = 2;
				else if (i == 2) i = 3;
				else i = 1;
			}
		} else if (b == 2) {
			for (int &i : pre) {
				if (i == 0) i = 0;
				else if (i == 1) i = 3;
				else if (i == 2) i = 1;
				else i = 2;
			}
		}
		now = 1;
		lli aa = 0;
		fop (i,0,pre.size()) {
			aa += pre[i] * now;
			now *= 4;
		}
		if (b == 0) {
			cout << ans << endl;
		} else {
			cout << (ans - c) * (b + 1) + aa << endl;
		}
    }
}