#include <bits/stdc++.h>

using namespace std;

string A[50005];

bool cmp (string a, string b) {
	return a + b < b + a;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n, cmp);
	string Ret = "";
	for (int i = 0; i < n; i++) Ret += A[i];
	cout << Ret << endl;
	return 0;
}