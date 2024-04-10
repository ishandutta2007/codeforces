#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())

string s;
vector<string> a;
int ans, tsz = 1;
vector<vector<int>> to(300001, vector<int>(26, -1));
vector<bool> term(300001, false);
vector<int> cterm(300001, 0), dep(300001);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(getline(cin, s)) {
		ans++;
		bool word = false;
		for(char ch : s) if(isalpha(ch)) {
			if(!word) a.push_back(string(1, ch)), word = true;
			else a.back().push_back(ch);
		} else {
			word = false;
			ans++;
		}
	}
	dep[0] = 0;
	for(int i = 0; i < sz(a); i++) {
		int v1 = -1, v2 = -1, v = 0;
		for(int j = 0; j < sz(a[i]); j++) {
			int ch = a[i][j] - 'a';
			if(to[v][ch] == -1) {
				to[v][ch] = tsz;
				dep[tsz] = dep[v] + 1;
				tsz++;
			}
			v = to[v][ch];
			if(cterm[v] == 1 && v1 == -1) v1 = v;
			if(term[v]) v2 = v;
		}
		if(!term[v]) {
			v = 0;
			for(int j = 0; j < sz(a[i]); j++) {
				int ch = a[i][j] - 'a';
				v = to[v][ch];
				cterm[v]++;
			}
			term[v] = true;
		}
		ans += sz(a[i]);
		if(v1 != -1 && v2 != -1) ans -= max(0, dep[v2] - dep[v1] - 1);
	}
	cout << ans;
}