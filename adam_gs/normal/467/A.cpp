#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b-a>=2) {
            ++r;
        }
    }
    cout << r;
}