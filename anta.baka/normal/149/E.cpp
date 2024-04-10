#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; int m, ans = 0; cin >> s >> m;
	while(m--) {
		string t; cin >> t;

		string z = t + '#' + s;
		vector<int> p(sz(z));
		p[0] = 0;
		for(int i = 1; i < sz(z); i++) {
			int k = p[i - 1];
			while(k && z[k] != z[i]) k = p[k - 1];
			if(z[k] == z[i]) k++;
			p[i] = k;
		}

		vector<int> pref(sz(s));
		pref[0] = p[sz(t) + 1];
		for(int i = 1; i < sz(s); i++) pref[i] = max(pref[i - 1], p[i + sz(t) + 1]);

		reverse(all(t));
		reverse(all(s));
		z = t + '#' + s;
		reverse(all(s));
		p[0] = 0;
		for(int i = 1; i < sz(z); i++) {
			int k = p[i - 1];
			while(k && z[k] != z[i]) k = p[k - 1];
			if(z[k] == z[i]) k++;
			p[i] = k;
		}

		vector<int> suff(sz(s));
		suff[0] = p[sz(t) + 1];
		for(int i = 1; i < sz(s); i++) suff[i] = max(suff[i - 1], p[i + sz(t) + 1]);
		reverse(all(suff));

		for(int i = 0; i < sz(s); i++) pref[i] = min(pref[i], sz(t) - 1);
		for(int i = 0; i < sz(s); i++) suff[i] = min(suff[i], sz(t) - 1);

		for(int i = 0; i < sz(s) - 1; i++)
			if(pref[i] + suff[i + 1] >= sz(t)) {
				ans++; break;
			}
	}
	cout << ans;
}