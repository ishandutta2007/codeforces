#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    x%=4;
    if (x==1) {
        cout << 0 << " A";
    }
    if (x==3) {
        cout << 2 << " A";
    }
    if (x==0) {
        cout << 1 << " A";
    }
    if (x==2) {
        cout << 1 << " B";
    }
}