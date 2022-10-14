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

int main () {
	string s;
	cin >> s;
	vector <int> a, b;
	fop (i,0,s.length()) {
		if (s[i] == '(') a.pb(i);
		else b.pb(i);
	}
	reverse(b.begin(), b.end());
	set <int> ans;
	for (int i = 0; i < a.size() and i < b.size(); ++i) {
		if (a[i] > b[i]) continue;
		ans.insert(a[i]);
		ans.insert(b[i]);
	}
	if (ans.size()) {
		cout << 1 << endl << ans.size() << endl;
		for (int i : ans) cout << i + 1 << ' ';
		cout << endl;
	} else {
		cout << 0 << endl;
	}
}