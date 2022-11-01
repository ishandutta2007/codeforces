#include <bits/stdc++.h>

using namespace std;

string s;
int n, p[105];

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", p + i);
	getline(cin, s);
	
	bool flag = 1;
	for (int j = 1; j <= n; ++j) {
		getline(cin, s);

		if (flag == 0) continue;

		int vowel = 0;
		for (int i = 0; i < s.size(); ++i) 
			if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'y')
				++vowel;
		if (vowel != p[j]) flag = 0;
	}

	puts(flag ? "YES" : "NO");
    return 0;
}