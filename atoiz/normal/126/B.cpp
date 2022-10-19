#include <iostream>
#include <string>
using namespace std;
int Z[1000007];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	int n = str.size();
    str += '-';

    Z[0] = n;
    while (str[Z[1]] == str[1 + Z[1]]) ++Z[1];
	int L = 1, R = Z[1];
	for (int i = 2; i < n; ++i) {
        if (i <= R) Z[i] = min(Z[i-L], R-i+1);
        while (str[Z[i]] == str[i + Z[i]]) ++Z[i];
        if (i + Z[i] - 1 > R) L = i, R = i + Z[i] - 1;
	}

	int m = 0, ans = 0;
    for (int i = 1; i < n; ++i) m = max(m, min(Z[i], n-i-1));
    for (int i = m; i > 0 && ans == 0; --i) if (Z[n-i] == i) ans = i;
    if (ans > 0) for (int i = 0; i < ans; ++i) cout << str[i];
    else cout << "Just a legend";
}