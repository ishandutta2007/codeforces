#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 100087

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n-2], b[n-2], c[n-2], count[n], p, p1;
	fop (i,0,n) count[i] = 0;
	fop (i,0,n-2) {
		cin >> a[i] >> b[i] >> c[i];
		count[a[i]-1]++;
		count[b[i]-1]++;
		count[c[i]-1]++;
	}
	fop (i,0,n) {
		if (count[i] == 1) p = i + 1;
	}
	map <pii, int> m1, m2;
	fop (i,0,n-2) {
		if (a[i] == p) {
			if (count[b[i]-1] == 2) p1 = b[i];
			if (count[c[i]-1] == 2) p1 = c[i];
		} else if (b[i] == p) {
			if (count[a[i]-1] == 2) p1 = a[i];
			if (count[c[i]-1] == 2) p1 = c[i];
		} else if (c[i] == p) {
			if (count[b[i]-1] == 2) p1 = b[i];
			if (count[a[i]-1] == 2) p1 = a[i];
		}
		vector <int> aa;
		aa.pb(a[i]);
		aa.pb(b[i]);
		aa.pb(c[i]);
		sort(aa.begin(), aa.end());
		do {
			if (m1.count({aa[0],aa[1]})) m2[{aa[0],aa[1]}] = aa[2];
			else m1[{aa[0],aa[1]}] = aa[2];
		} while (next_permutation(aa.begin(), aa.end()));
	}
	int ans[n];
	ans[0] = p;
	ans[1] = p1;
	set <int> s1;
	s1.insert(p);
	s1.insert(p1);
	fop (i,2,n) {
		if (m1.count({ans[i-1], ans[i-2]}) and !s1.count(m1[{ans[i-1], ans[i-2]}])) ans[i] = m1[{ans[i-1], ans[i-2]}];
		else ans[i] = m2[{ans[i-1], ans[i-2]}];
		s1.insert(ans[i]);
	}
	fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}