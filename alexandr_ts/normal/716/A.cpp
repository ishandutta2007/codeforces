#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
        if (a[i] - a[i - 1] > c) {
            cout << n - i;
            return 0;
        }
    cout << n;

}