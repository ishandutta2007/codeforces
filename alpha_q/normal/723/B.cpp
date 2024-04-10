#include <bits/stdc++.h>

using namespace std;

int n; char s[300];

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	scanf("%s", s + 1);

	bool start = 0, parOpen = 0;
	int curLen = 0, maxWord = 0, cntPar = 0;
	for (int i = 1; i <= n; ++i) {
		if (isalpha(s[i])) {
			++curLen;
		}
		else if (s[i] == '_') {
			if (curLen) {
				if (parOpen) ++cntPar;
				else maxWord = max(maxWord, curLen);
				curLen = 0;
			} 
		}
		else if (s[i] == '(') {
			if (curLen) maxWord = max(maxWord, curLen);
			curLen = 0;
			parOpen = 1;
		}
		else if (s[i] == ')') {
			if (curLen) ++cntPar;
			curLen = 0, parOpen = 0;
		}
	}
	if (curLen) maxWord = max(maxWord, curLen);

	printf("%d %d\n", maxWord, cntPar);
	return 0;
}