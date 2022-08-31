#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    int res = 0;
    for (int i = 1; i <= n - 1; i += 2) {
        res++;
        if (i == a || n - (i - 1) == a)
            break;
    }
    cout << res << endl;
}