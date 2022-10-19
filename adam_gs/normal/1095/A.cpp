#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int i = 0;
    int l = 1;
    while (i<n) {
        cout << x[i];
        i+=l;
        l+=1;
    }
}