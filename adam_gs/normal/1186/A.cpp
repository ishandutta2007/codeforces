#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n-min(m, k)>0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}