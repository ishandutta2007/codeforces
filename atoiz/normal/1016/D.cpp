#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    #define endl '\n'
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int xa = 0, xb = 0;
    for (int i = 0; i < n; ++i) xa ^= a[i];
    for (int i = 0; i < m; ++i) xb ^= b[i];
    if (xa != xb) {
		cout << "NO" << endl;
		return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m-1; ++j) {
            cout << "0 ";
        }
        cout << a[i] << endl;
    }
    for (int j = 0; j < m-1; ++j) cout << b[j] << ' ';
    cout << (xa ^ a[n-1] ^ b[m-1]) << endl;
}