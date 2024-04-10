#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string x;
        cin >> x;
        if (x[x.size()-2]=='p') {
            cout << "FILIPINO";
        } else if (x[x.size()-2]=='s') {
            cout << "JAPANESE";
        } else {
            cout << "KOREAN";
        }
        cout << '\n';
    }
}