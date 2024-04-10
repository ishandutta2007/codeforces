#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ,res = 0;
    cin >> n;
    for (int i = 1; ; i++) {
        int u = i / 2;
        if (u * (i - u) >= n) {
            cout << i;
            break;
        }
    }
}