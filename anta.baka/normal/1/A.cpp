/*
 
























*/

#include <bits/stdc++.h>

using namespace std;

int nextInt() {
	int x;
	cin >> x;
	return x;
}

int main() {
    int n = nextInt();
    int m = nextInt();
    int a = nextInt();
    cout << 1LL * ((n + a - 1) / a) * ((m + a - 1) / a);
}