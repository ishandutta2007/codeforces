#include <bits/stdc++.h>

using namespace std;

int main() {
    int t[4];
    cin >> t[0] >> t[1] >> t[2] >> t[3];
    sort(t,t+4);
    if (t[3]+t[0]==t[2]+t[1] || t[0]+t[1]+t[2]==t[3]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}