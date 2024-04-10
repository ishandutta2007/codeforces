#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a==b) {
            cout << 0;
        } else if (a<b && (b-a)%2==1) {
            cout << 1;
        } else if (a>b && (a-b)%2==0) {
            cout << 1;
        } else {
            cout << 2;
        }
        cout << '\n';
    }
}