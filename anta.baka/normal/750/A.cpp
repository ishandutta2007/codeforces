#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int s = 0;
	for(int i = 0; i <= n; i++) {
		if(i == n || s + (i+1)*5 + k > 240)
			return cout << i,0;
		s += (i+1)*5;
	}
}