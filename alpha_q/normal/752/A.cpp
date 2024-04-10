#include <bits/stdc++.h> 

using namespace std;

int n, m, k;

int main (int argc, char const *argv[]) {
	cin >> n >> m >> k;
	char c = k & 1 ? 'L' : 'R';
	++k, k >>= 1;
	int lane = (k + m - 1)/m;
	int desk = k % m;
	if (desk == 0) desk = m;
	cout << lane << " " << desk << " " << c << endl;
	return 0;
}