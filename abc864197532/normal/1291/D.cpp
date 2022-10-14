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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector <int> abc[26];
	int count = 0;
	for (char c : s) {
		abc[c-'a'].pb(++count);
	}
	int t, l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		if (r - l == 0) cout << "Yes" << endl;
		else {
			if (s[l-1] != s[r-1]) cout << "Yes" << endl;
			else {
				count = 0;
				fop (i,0,26) {
					if (abc[i].empty()) continue;
					auto it = lower_bound(abc[i].begin(), abc[i].end(), l);
					if (it == abc[i].end()) continue;
					if (*it <= r) count++;
				}
				if (count <= 2) cout << "No" << endl;
				else cout << "Yes" << endl;
			}
		}
	}
}