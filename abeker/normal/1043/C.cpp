#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	s += 'b';
	for (int i = 0; i + 1 < s.size(); i++)
		printf("%d ", s[i] != s[i + 1]);
	puts("");
	
	return 0;
}