#include <bits/stdc++.h>
using namespace std;

vector <multiset <string>> ask(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int len = r - l + 1;
	int subs = len * (len + 1) / 2;
	vector <multiset <string>> res(len + 1);
	while (subs--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		res[s.size()].insert(s);
	}
	return res;
}

string remove(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	s += '*';
	t += '*';
	int ptr = -1;
	string res = "";
	for (auto it : t)
		for (ptr++; ptr < s.size() && s[ptr] != it; ptr++) 
			res += s[ptr];
	return res;
}

void finish(string res) {
	printf("! %s\n", res.c_str());
	fflush(stdout);
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	
	int N;
	scanf("%d", &N);
	
	vector <multiset <string>> all = ask(1, N);
	
	if (N == 1)
		finish(*all[1].begin());
	
	vector <multiset <string>> pref = ask(1, N - 1);
	
	string perm_all = *all[N].begin();
	string perm_pref = *pref[N - 1].begin();
	
	string ans;
	ans.resize(N);
	ans[N - 1] = remove(perm_all, perm_pref)[0];
	for (int i = 0; i < N; i++) {
		int len = N - i - 1;
		for (int j = 0; j < i + 1; j++) {
			string rest = ans.substr(0, j) + ans.substr(j + len, N - j - len);
			string curr = remove(perm_all, rest);
			all[len].erase(all[len].find(curr));
		}
		string tmp = remove(remove(perm_all, ans.substr(0, i)), *all[len].begin());
		ans[i] = tmp[0];
		if (i >= N - i - 2)
			break;
		len = N - i - 2;
		for (int j = 1; j < i + 2; j++) {
			string rest = ans.substr(0, j) + ans.substr(j + len, N - 1 - j - len);
			string curr = remove(perm_pref, rest);
			pref[len].erase(pref[len].find(curr));
		}
		tmp = remove(remove(perm_pref, ans.substr(len + 1, N - 2 - len)), *pref[len].begin());
		ans[N - i - 2] = tmp[0];
	}
	
	finish(ans);
	
	return 0;
}