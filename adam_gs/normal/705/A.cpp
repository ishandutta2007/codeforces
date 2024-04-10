#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "I hate ";
    int i = 0;
    while (--n) {
        cout << "that ";
        if (i%2==0) {
            cout << "I love ";
        } else {
            cout << "I hate ";
        }
        ++i;
    }
    cout << "it";
}