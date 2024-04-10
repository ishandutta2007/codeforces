#include <bits/stdc++.h>

using namespace std;

int main() {
    int r=0;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int a;
            cin >> a;
            if (a==1) {
                r+=abs(i-3);
                r+=abs(j-3);
            }
        }
    }
    cout << r;
}