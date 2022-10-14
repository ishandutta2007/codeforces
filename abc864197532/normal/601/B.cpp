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

int main() {
	int n, q, tmp, tmp2, ll, rr;
	cin >> n >> q >> tmp;
	int a[n-1];
	fop (i,0,n-1) {
		cin >> tmp2;
		a[i] = abs(tmp2 - tmp);
		tmp = tmp2;
	}
	while (q--) {
		cin >> ll >> rr;
		ll--, rr--;
		stack <int> left, right;
		vector <int> l, r;
		fop (i,ll,rr) {
			while (left.size() and a[left.top()] < a[i]) left.pop();
			if (left.size()) l.push_back(i - left.top());
			else l.push_back(i - ll + 1);
			left.push(i);
		}
		FOP (i,rr,ll) {
			while (right.size() and a[right.top()] <= a[i]) right.pop();
			if (right.size()) r.push_back(right.top() - i);
			else r.push_back(rr - i);
			right.push(i);
		}
		lli ans = 0;
		fop (i,0,l.size()) {
			ans += (1ll * l[i] * r[l.size() - i - 1] * a[i + ll]);
		}
		cout << ans << endl;
	}
}