#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a<=3) {
            cout << 4-a;
        } else if (a%2==0) {
            cout << 0;
        } else {
            cout << 1;
        }
        cout << '\n';
    }
}