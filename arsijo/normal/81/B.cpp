#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define y1 ngsdf
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;
const int MAX = 1e9;

int main() {

	string s;
	getline(cin, s);

	string ans = "";
	string st = "";
	bool bol = true;
	for (int i = 0; i < (int) s.length(); i++) {
		if (s[i] == ' ') {
			if (st.length() != 0 && st[st.length() - 1] != ' '
					&& st[st.length() - 1] != '.' && bol && ans != "")
				st += ' ';
			if (bol && ans != "") {
				st += ans;
				ans = "";
			}
			bol = true;
		} else if (s[i] == ',') {
			if (ans.length() == 0) {
				if (st.length() != 0 && st[st.length() - 1] == ',')
					st += ' ';
			} else {
				if (st.length() != 0
						&& (st[st.length() - 1] != '.'
								&& st[st.length() - 1] != ' '))
					st += ' ';
			}
			st += ans + ",";
			ans = "";
			//bol = false;
		} else if (s[i] == '.' && ans.size() > 1 && ans[ans.size() - 1] == '.'
				&& ans[ans.size() - 2] == '.') {
			if (st.length() != 0 && st[st.length() - 1] != ' '
					&& st[st.length() - 1] != '.')
				st += ' ';
			for (int j = 0; j < (int) ans.length() - 2; j++)
				st += ans[j];
			if (st.length() != 0 && st[st.length() - 1] != ' ')
				st += ' ';
			st += "...";
			ans = "";
			//bol = false;
			if (i != (int) s.length() - 1 && s[i + 1] == ',') {
				st += ",";
				i++;
			}
		} else
			ans += s[i];
	}

	if (ans != "") {
		if (st.length() != 0 && st[st.length() - 1] != ' '
				&& st[st.length() - 1] != '.')
			st += ' ';
		st += ans;
	}

	cout << st;

}