#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if ((x[i]-'0')%2==0) {
            r+=i+1;
        }
    }
    cout << r;
}