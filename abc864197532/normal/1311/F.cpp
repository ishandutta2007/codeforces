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
#define pli pair<lli,int> 
#define X first
#define Y second

struct BIT {
	vector <int> sum; int n;
	BIT (int n) : n(n) {sum.resize(n + 1);}
	void add (int p, int a) {for (int i = p; i <= n; i += (i & -i)) sum[i] += a;}
	int query (int p) {int all = 0; for (int i = p; i > 0; i -= (i & -i)) all += sum[i]; return all;}
	int kth (int k) {
		int ans = 0;
		for (int i = 1 << __lg(n); i > 0; i >>= 1) if (ans + i <= n and sum[ans + i] < k) k -= sum[ans += i];
		return ans + 1;
	}
};

int main () {
    int n;
    cin >> n;
    vector <pii> x(n);
    vector <int> v(n);
    fop (i,0,n) {
        cin >> x[i].X;
    }
    fop (i,0,n) {
        cin >> v[i];
    }
    vector <int> a = v;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    fop (i,0,n) x[i].Y = lower_bound(a.begin(), a.end(), v[i]) - a.begin() + 1;
    sort(x.begin(), x.end());
    BIT bit(a.size()), bit2(a.size());
    lli ans = 0;
    fop (i,0,n) {
        ans += 1ll * x[i].X * bit.query(x[i].Y);
        bit.add(x[i].Y, 1);
    }
    FOP (i,n,0) {
        ans -= 1ll * x[i].X * (bit2.query(a.size()) - bit2.query(x[i].Y - 1));
        bit2.add(x[i].Y, 1);
    }
    cout << ans << endl;
}