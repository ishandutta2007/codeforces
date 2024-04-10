#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int a=0;
    int d=0;
    for (int i = 0; i < n; ++i) {
        if (x[i]=='A') {
            ++a;
        } else {
            ++d;
        }
    }
    if (a>d) {
        cout << "Anton";
    } else if (a<d) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }
}