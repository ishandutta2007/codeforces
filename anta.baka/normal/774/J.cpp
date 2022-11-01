#include <bits/stdc++.h>

using namespace std;

int f(string s) {
	int res = 0;
	int cur = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == 'N')
			cur++;
		else {
			res = max(res, cur);
			cur = 0;
		}
	return max(res, cur);
}

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++) {
		string b = s;
		for(int j = 0; j < i; j++)
			if(b[j] == '?')
				b[j] = 'Y';
		for(int j = i; j < i + k; j++)
			if(b[j] == '?')
				b[j] = 'N';
		for(int j = i + k; j < n; j++)
			if(b[j] == '?')
				b[j] = 'Y';
		if(f(b) == k) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}