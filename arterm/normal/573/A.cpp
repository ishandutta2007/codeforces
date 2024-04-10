#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

int n, a[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        while (a[i] % 2 == 0)
            a[i] /= 2;
        while (a[i] % 3 == 0)
            a[i] /= 3;
    }
    if (*max_element(a, a + n) == *min_element(a, a + n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}