#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef pair <char, char> pii;

vector <pii> sol;
map <char, char> f;

vector <int> occ(string x, char c) {
	vector <int> res;
	for (int i = 0; i < x.size(); i++)
		if (x[i] == c)
			res.push_back(i);
	return res;
}

int main() {
	string s, t;
	cin >> s >> t;
	for (char i = 'a'; i <= 'z'; i++)
		f[i] = i;
	for (char i = 'a'; i <= 'z'; i++)
		for (char j = i + 1; j <= 'z'; j++) {
			vector <int> a = occ(s, i);
			vector <int> b = occ(s, j);
			vector <int> c = occ(t, i);
			vector <int> d = occ(t, j);
			if ((!a.empty() || !b.empty()) && a == d && b == c) {
				sol.push_back({i, j});
				f[i] = j;
				f[j] = i;
			}
		}

	for (int i = 0; i < s.size(); i++)
		s[i] = f[s[i]];
	
	if (s != t) {
		puts("-1");
		return 0;
	}
	
	printf("%d\n", sol.size());
	for (auto it : sol)
		printf("%c %c\n", it.first, it.second);
			
	return 0;
}