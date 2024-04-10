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
const int N = 1000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	lli k;
	cin >> n >> m >> k;
	int now = 0, tmp;
	vector <int> a, b;
	fop (i,0,n) {
	    cin >> tmp;
	    if (tmp) now++;
	    else if (now) a.pb(now), now = 0;
	}
	if (now) a.pb(now);
	now = 0;
	fop (i,0,m) {
	    cin >> tmp;
	    if (tmp) now++;
	    else if (now) b.pb(now), now = 0;
	}
	if (now) b.pb(now);
	vector <lli> aa(40087, 0), bb(40087, 0);
	for (int i : a) {
	    int k = i;
	    while (i) {
	        aa[i] += k - i + 1;
	        i--;
	    }
	}
	for (int i : b) {
	    int k = i;
	    while (i) {
	        bb[i] += k - i + 1;
	        i--;
	    }
	}
	lli ans = 0;
	for (int i = 1; i * i <= k; ++i) {
	    if (k % i) continue;
	    if (k / i >= 40087 or i >= 40087) continue;
	    ans += 1ll * aa[i] * bb[k / i];
	    if (i * i != k) ans += 1ll * aa[k / i] * bb[i];
	}
	cout << ans << endl;
}