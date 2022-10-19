#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a1=0, a2=0, b1=0, b2=0;
    while (n--) {
        int a, b, c;
        cin >> a >> b>>c;
        if (a==1) {
            a1+=b;
            a2+=c;
        } else {
            b1+=b;
            b2+=c;
        }
    }
    if (a1>=a2) {
        cout << "LIVE\n";
    } else {
        cout << "DEAD\n";
    }
    if (b1>=b2) {
        cout << "LIVE";
    } else {
        cout << "DEAD";
    }
}