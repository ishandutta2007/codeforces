#include <bits/stdc++.h>

using namespace std;

unsigned short int f[19000000];

int main() {
    int l, r;
    cin >> l >> r;
    l = (l == 1 ? 2 : l);
    int SQRT = sqrt(r) + 1;
    for (int i = 3; i <= SQRT; i += 2) 
	if (!(f[i >> 4] & (1 << (i % 16)))) 
	    for (int j = i * i; j <= r; j += i) 
		f[j >> 4] = (f[j >> 4] | (1 << (j % 16)));
    int ans = 0;
    for (int i = l + (1 - l % 2); i <= r; i += 2) 
	ans += (i % 4 == 1 && ((f[i >> 4] & (1 << (i % 16))) == 0));
    cout << ans + (2 >= l && 2 <= r) << endl;
}