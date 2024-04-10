#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (2 * (a[0] + a[1]) < a[2]){
        cout << a[0] + a[1] << endl;
        return 0;
    }
    cout << (a[0] + a[1] + a[2]) / 3 << endl;
}