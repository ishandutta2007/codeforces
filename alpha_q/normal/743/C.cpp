#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
    int n; cin >> n;
    if (n == 1) {
    	puts("-1");
    	return 0;
    }
    cout << n << " " << n + 1 << " " << n * (n + 1) << '\n';
    return 0;
}