#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int r = 0;
    for (int i = 0; i <k; ++i) {
        r+=2*(n+m-8*i-2);
    }
    cout << r;
}