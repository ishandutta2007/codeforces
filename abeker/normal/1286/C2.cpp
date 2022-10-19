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

string solve(int n) {
	vector <multiset <string>> all = ask(1, n);
	if (n == 1)
		return *all[1].begin();
	vector <multiset <string>> pref = ask(1, n - 1);
	
	string perm_all = *all[n].begin();
	string perm_pref = *pref[n - 1].begin();
	
	string ans;
	ans.resize(n);
	ans[n - 1] = remove(perm_all, perm_pref)[0];
	for (int i = 0; i < n; i++) {
		int len = n - i - 1;
		for (int j = 0; j < i + 1; j++) 
			all[len].erase(all[len].find(remove(perm_all, ans.substr(0, j) + ans.substr(j + len, n - j - len))));
		ans[i] = remove(remove(perm_all, ans.substr(0, i)), *all[len].begin())[0];
		if (i >= n - i - 2)
			break;
		len = n - i - 2;
		for (int j = 1; j < i + 2; j++) 
			pref[len].erase(pref[len].find(remove(perm_pref, ans.substr(0, j) + ans.substr(j + len, n - 1 - j - len))));
		ans[n - i - 2] = remove(remove(perm_pref, ans.substr(len + 1, n - 2 - len)), *pref[len].begin())[0];
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	
	int N;
	scanf("%d", &N);
	
	int third = N / 3;
	string ans = solve(N - third);
	ans.resize(N);
	
	if (N <= 2)
		finish(ans);
	
	vector <multiset <string>> suff = ask(third + 1, N);
	string perm_suff = *suff[N - third].begin();
	
	for (int i = 1; i <= third; i++) {
		int len = N - third - i;
		for (int j = third + 1; j <= N - len; j++) 
			suff[len].erase(suff[len].find(remove(perm_suff, ans.substr(third, j - third) + ans.substr(j + len, N - j - len))));
		ans[N - i] = remove(remove(perm_suff, ans.substr(third + len + 1, N - third - len - 1)), *suff[len].begin())[0];
	}
	
	finish(ans);
	
	return 0;
}