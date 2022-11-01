#include <bits/stdc++.h>

using namespace std;

int n, m, A[12] = {0}, i, j, ret = 0;

int main () {
    cin >> n >> m;
    while (n--) cin >> i, A[i]++;

    for (i = 1; i < m; i++)
	    for (j = i + 1; j <= m; j++)
		    ret += A[i] * A[j];

    cout << ret << endl;
    return 0;
}