#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    if (m - 1 >= n - (m + 1) + 1)
        cout << m - 1 << endl;
    else
        cout << m + 1 << endl;
}