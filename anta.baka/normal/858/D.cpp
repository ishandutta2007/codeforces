#include <bits/stdc++.h>

using namespace std;

int n;
string s[70000];
unordered_map<long long, int> mem;

long long P = 1e9 + 7;

long long key(string s) {
	long long ret = 0;
	for(char x : s)
		ret = ret * P + x;
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mem.rehash(70000 * 9 * 10 / 2);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int l = 0; l < 9; l++) {
			string cur;
			for(int r = l; r < 9; r++) {
				cur += s[i][r];
				if(mem.count(key(cur)) == 0)
					mem[key(cur)] = i;
				else if(mem[key(cur)] != i)
					mem[key(cur)] = -1;
			}
		}
	}
	for(int i = 0; i < n; i++)
		for(int len = 1; len <= 9; len++) {
			bool done = false;
			for(int j = len - 1; j < 9; j++)
				if(mem[key(s[i].substr(j - len + 1, len))] == i) {
					done = true;
					cout << s[i].substr(j - len + 1, len) << '\n';
					break;
				}
			if(done)
				break;
		}
}