#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a+b+c>=2) {
            ++r;
        }
    }
    cout << r;
}