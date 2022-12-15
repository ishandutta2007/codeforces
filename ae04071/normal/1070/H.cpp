#include <bits/stdc++.h>
using namespace std;
int n, Q;
map<string,int> mp1;
map<string,string> mp2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	string s;
	for(int i=1; i<=n; i++) {
		cin >> s;
		int len = s.length();
		set<string> st;
		for(int j=0; j<len; j++) {
			for(int k=1; k<=len-j; k++) {
				st.insert(s.substr(j,k));
			}
		}
		//cout << "i:" << i << '\n';
		for(auto& it : st) {
			mp1[it]++;
			mp2[it] = s;
			//cout << it << '\n';
		}
	}
	cin >> Q;
	for(int i=0; i<Q; i++) {
		cin >> s;
		cout << mp1[s] << ' ' << (mp2.count(s) > 0 ? mp2[s] : "-") << '\n';
	}
	return 0;
}