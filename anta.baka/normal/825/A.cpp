#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int t = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == '0') cout << t, t = 0;
		else t++;
	cout << t;
}