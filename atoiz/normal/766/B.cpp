#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    for (int i = 2; i < n; ++i) {
		if (a[i-2] + a[i-1] > a[i]) {
			cout << "YES" << endl;
			return 0;
		}
    }
    cout << "NO" << endl;
}