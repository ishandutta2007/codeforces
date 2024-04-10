# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
string s[MAXN];
set <string> st;
bool check(){
	st.clear();
	for (int i = n; i >= 1; i--){
		string s1 = s[i];
		reverse(s1.begin(), s1.end());
		if (s[i] == s1) return true;
		if (s[i].size() == 2){
			if (st.find(s1) != st.end()) return true;
			for (char j = 'a'; j <= 'z'; j++){
				if (st.find(j + s1) != st.end()) return true;
			}
		} else {
			if (st.find(s1) != st.end()) return true;
			if (st.find(s1.substr(1, 3)) != st.end()) return true;
		}
		st.insert(s[i]);
	}
	return false;
}
int main(){
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i];
		if (check()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}