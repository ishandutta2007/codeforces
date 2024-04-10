#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int cur = 1;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n == 3) {
        cout << "1 1 3";
        return 0;
    }
    int k = n;
    while (n != 1) {
        for (int i = 0; i < n / 2 + n % 2; i++)
            cout << cur << " ";
        cur *= 2;
        n /= 2;
    }
    cur /= 2;

    //if (k == 3 || k == 1) cout << k;
    cout << k - k % cur;
    return 0;
}