#include <bits/stdc++.h>

using namespace std;

long long a[1000];

int main() {
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        if (n % 2 == 0 && n >= 4){
            cout << n / 4 << endl;
            continue;
        }
        else
            n -= 9;
        if (n == 0)
            cout << 1 << endl;
        else if (n < 4)
            cout << -1 << endl;
        else
            cout << n / 4 + 1 << endl;
    }
}