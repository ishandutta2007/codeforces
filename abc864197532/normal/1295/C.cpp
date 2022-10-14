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
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		vector <int> abc[26];
		fop (i,0,s1.length()) {
			abc[s1[i]-'a'].pb(i);
		}
		int ans = 1, now = -1;
		fop (i,0,s2.length()) {
			if (abc[s2[i] - 'a'].size() == 0) {
				ans = -1;
				break;
			}
			auto it = upper_bound(abc[s2[i] - 'a'].begin(), abc[s2[i] - 'a'].end(), now);
			if (it == abc[s2[i] - 'a'].end()) {
				ans++;
				now = -1;
				it = upper_bound(abc[s2[i] - 'a'].begin(), abc[s2[i] - 'a'].end(), now);
			}
			now = *it;
		}
		cout << ans << endl;
	}
}