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

int main () {
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	string s;
    	map <string, int> m1[2]; // 01 10
    	bool is = false, iss = false;
    	int aa = 0, bb = 0;
    	fop (i,0,n) {
    		cin >> s;
    		if (s[0] == '0' and s[s.length()-1] == '1') {
    			m1[0][s] = i + 1;
				aa++;
			}
    		if (s[0] == '1' and s[s.length()-1] == '0') {
    			m1[1][s] = i + 1;
				bb++;
			}
    		if (s[0] == '0' and s[s.length()-1] == '0') {
    			is = true;
			}
    		if (s[0] == '1' and s[s.length()-1] == '1') {
    			iss = true;
			}
		}
		if (aa == 0 and bb == 0 and is and iss) {
			cout << -1 << endl;
			continue;
		}
		vector <int> ans;
		int need = abs(aa - bb) / 2;
		if (aa > bb) {
			for (auto i : m1[0]) {
				if (need == 0) break;
				s = i.first;
				reverse(s.begin(), s.end());
				if (!m1[1].count(s)) {
					ans.pb(i.second);
					need--;
				}
			}
		} else {
			for (auto i : m1[1]) {
				if (need == 0) break;
				s = i.first;
				reverse(s.begin(), s.end());
				if (!m1[0].count(s)) {
					ans.pb(i.second);
					need--;
				}
			}
		}
		if (need == 0) {
			cout << ans.size() << endl;
			fop (i,0,ans.size()) cout << ans[i] << ' ';
			cout << endl;
		} else {
			cout << -1 << endl; 
		}
    }
}