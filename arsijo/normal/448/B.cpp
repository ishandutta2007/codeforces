/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

string t, s;

bool isAutomaton() {
	int pos = 0;
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == s[pos])
			pos++;
		if (pos == s.length())
			return true;
	}
	return false;
}

int a[26];

bool isArray() {
	memset(a, 0, sizeof(a));
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < t.length(); i++) {
		a[t[i] - 'a']--;
	}
	if (s.length() != t.length())
		return false;

	for (int i = 0; i < 26; i++)
		if (a[i] != 0)
			return false;
	return true;
}

bool isBoth() {
	if (t.length() < s.length())
		return false;
	for (int i = 0; i < 26; i++) {
		if (a[i] > 0)
			return false;
	}
	return true;
}

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	getline(cin, t);
	getline(cin, s);
	if (isAutomaton()) {
		cout << "automaton";
	} else if (isArray()) {
		cout << "array";
	} else if (isBoth()) {
		cout << "both";
	} else {
		cout << "need tree";
	}
}