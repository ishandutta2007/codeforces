#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m=0;
    int c=0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a>b) {
            ++m;
        }
        if (b>a) {
            ++c;
        }
    }
    if (m>c) {
        cout << "Mishka";
    } else if (m<c) {
        cout << "Chris";
    } else {
        cout << "Friendship is magic!^^";
    }
}