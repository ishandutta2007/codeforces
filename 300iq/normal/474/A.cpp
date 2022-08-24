#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	char c;
	cin >> c;
	int m = (c == 'L' ? 1 : -1);
	string abc = "qwertyuiopasdfghjkl;zxcvbnm,./";
	map <char, int> press;
	for (int i = 0; i < (int) abc.length(); i++)
		press[abc[i]] = i;
	string s;
	cin >> s;
	for (int i = 0; i < (int) s.length(); i++)
		cout << abc[press[s[i]] + m];
}