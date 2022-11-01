#include <bits/stdc++.h>

using namespace std;

int main() {
	long long P[500005], n; string S;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> P[i];
	cin >> S;
	long long B = 0, Ret = 0, Sum;
	for (int i = 0; i < n; i++)
		if (S[i] == 'B') B += P[i];

	Ret = B, Sum = B;
	for (int i = 0; i < n; i++) {
		if (S[i] == 'A') Sum += P[i];
		else Sum -= P[i];
		Ret = max(Ret, Sum);
	}
	
	Sum = B;
	for (int i = n - 1; i >= 0; i--) {
		if (S[i] == 'A') Sum += P[i];
		else Sum -= P[i];
		Ret = max(Ret, Sum);
	}
	
	cout << Ret << endl;
	return 0;
}