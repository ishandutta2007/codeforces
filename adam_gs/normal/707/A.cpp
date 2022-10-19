#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool t = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            if (x!='B' && x!='W' && x!='G') t=false;
        }
    }
    if (t==true) {
        cout << "#Black&White";
    } else {
        cout << "#Color";
    }
}