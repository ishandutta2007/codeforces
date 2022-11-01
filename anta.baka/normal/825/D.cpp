#include <bits/stdc++.h>

using namespace std;

string s, t;
int ns, nt;
int cs[26], ct[26], cs0[26];
int q;
vector<int> pos;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s >> t;
	ns = s.size(), nt = t.size();
	for(char ch : s)
		if(ch == '?') q++;
		else cs[ch - 'a']++, cs0[ch - 'a']++;
	for(char ch : t)
		ct[ch - 'a']++;
	int cnt = 0;
	while(true) {
		bool flag = false;
		for(int i = 0; i < 26; i++)
			if(cs[i] >= ct[i]) cs[i] -= ct[i];
			else if(cs[i] + q >= ct[i]) q -= ct[i] - cs[i], cs[i] = 0;
			else { flag = true; break; }
		if(flag) break;
		cnt++;
	}
	for(int i = 0; i < ns; i++)
		if(s[i] == '?')
			pos.push_back(i);
	for(int i = 0; i < cnt; i++)
		for(char ch : t)
			if(cs0[ch - 'a'] != 0) cs0[ch - 'a']--;
			else s[pos.back()] = ch, pos.pop_back();
	for(char ch : s) cout << (ch == '?' ? 'a' : ch);
}