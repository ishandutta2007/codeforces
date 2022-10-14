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

vector <int> lastPrime (int n) {
	vector <int> ans(n + 1,0);
	for (int i = 2; i <= n; ++i) {
		if (ans[i] == 0) {
			for (int j = i; j <= n; j += i) {
				ans[j] = i;
			}
		}
	}
	return ans;
}

vector <int> make_mobius (int n) {
	vector <int> LPrime = lastPrime(n), mobius(n + 1);
	mobius[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (LPrime[i] == LPrime[i / LPrime[i]]) mobius[i] = 0;
		else mobius[i] = mobius[i / LPrime[i]] * -1;
	}
	return mobius;
}

int main () {
    int n, q, x;
    cin >> n >> q;
    vector <int> input(n), c(500001, 0), mb = make_mobius(500001);
    vector <vector <int>> factor(n, vector <int>());
    vector <bool> is(n, false);
    fop (i,0,n) {
        cin >> input[i];
        for (int j = 1; j * j <= input[i]; ++j) {
            if (input[i] % j == 0) {
                factor[i].pb(j);
                if (j * j != input[i]) factor[i].pb(input[i] / j);
            }
        }
    }
    lli ans = 0;
    while (q--) {
        cin >> x; x--;
        if (is[x]) {
            is[x] = false;
            for (int p : factor[x]) {
                c[p]--;
                ans -= mb[p] * c[p];
            }
        } else {
            is[x] = true;
            for (int p : factor[x]) {
                ans += mb[p] * c[p];
                c[p]++;
            }
        }
        cout << ans << '\n';
    }
}