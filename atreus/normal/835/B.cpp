#include <bits/stdc++.h>

using namespace std;

int ctr[100];

int main()
{
	int k, sum = 0;
	string s;
	cin >> k >> s;
	for (int c = 0; c < s.size(); c ++) {
		int x = s[c] - '0';
		ctr[x] ++;
		sum += x;
	}
	int d = 0, r = 0;
	while (sum < k) {
		if (sum + ctr[d] * (9 - d) < k) {
			sum += ctr[d] * (9 - d);
			r += ctr[d];
			++d;
		} else {
			int aux = (k - sum) / (9 - d);
			if (aux * (9 - d) + sum < k) ++aux;
			r += aux;
			sum += aux * (9 - d);
		}
	}
	cout << r << endl;
	return 0;
}