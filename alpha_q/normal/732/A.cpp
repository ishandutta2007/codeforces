#include <bits/stdc++.h>

using namespace std;

int k, r;

int main (int argc, char const *argv[]) {
	cin >> k >> r;
	for (int x = 1; x <= 10; ++x) {
		if ((k * x) % 10 == 0 or (k * x) % 10 == r) {
			cout << x << '\n';
			return 0;
		} 
	}
    return 0;
}