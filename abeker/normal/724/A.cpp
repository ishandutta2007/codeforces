#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const string day[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int get(string s) {
	for (int i = 0; i < 7; i++)
		if (day[i] == s) return i;
	return -1;
}

int main() {
	string a, b;
	cin >> a >> b;
	int diff = (get(b) - get(a) + 7) % 7;
	puts(diff == 0 || diff == 2 || diff == 3 ? "YES" : "NO");
	return 0;
}