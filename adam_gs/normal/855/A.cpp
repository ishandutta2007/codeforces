#include <bits/stdc++.h>

using namespace std;

map <string, int>T;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        if (T[x]==1) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
        T[x]=1;
    }
}