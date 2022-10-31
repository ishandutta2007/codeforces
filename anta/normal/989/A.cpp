#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	while (cin >> S) {
		bool ans = false;
		for (int i = 1; i < (int)S.size() - 1; ++ i) {
			string t;
			for (int k = 0; k < 3; ++ k)
				t += S[i - 1 + k];
			sort(t.begin(), t.end());
			ans |= t == "ABC";
		}
		puts(ans ? "Yes" : "No");
	}
}