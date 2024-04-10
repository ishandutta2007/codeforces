#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    int c = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i]>='a') {
            ++c;
        }
    }
    if (2*c>=x.size()) {
        for (int i = 0; i < x.size(); ++i) {
            char p = tolower(x[i]);
            cout << p;
        }
    } else {
        for (int i = 0; i < x.size(); ++i) {
            char p =toupper(x[i]);
            cout << p;
        }
    }
}