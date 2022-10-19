#include <bits/stdc++.h>
using namespace std;

int main() {
    string order = "v<^>";
    char c1, c2;
    int n;
    cin >> c1 >> c2 >> n;
    int n1 = 0;
    int n2 = 0;
    while (c1 != order[n1]) {
        n1++;
    }
    while (c2 != order[n2]) {
        n2++;
    }
    bool cw = (n1 + n) % 4 == n2;
    bool ccw = (n2 + n) % 4 == n1;
    if (cw && ccw) {
        cout << "undefined" << endl;
    } else if (cw) {
        cout << "cw" << endl;
    } else {
        cout << "ccw" << endl;
    }
}