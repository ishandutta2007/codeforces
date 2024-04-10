#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int s=0;
    int f=0;
    for (int i = 1; i < n; ++i) {
        if (x[i]=='F' && x[i-1]=='S') {
            ++f;
        }
        if (x[i]=='S' && x[i-1]=='F') {
            ++s;
        }
    }
    if (f>s) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}