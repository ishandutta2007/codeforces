#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool t = true;
    while (n--) {
        int a;
        cin >> a;
        if (a==1) {
            t=false;
        }
    }
    if (t==true) {
        cout << "EASY";
    } else {
        cout << "HARD";
    }
}