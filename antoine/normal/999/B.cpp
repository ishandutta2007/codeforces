// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
		if (n%i == 0)
			reverse(s.begin(), s.begin() + i);
	cout << s;
	return 0;
}