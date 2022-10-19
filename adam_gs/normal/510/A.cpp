#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i<=n; ++i) {
        string x="";
        for (int j = 1; j<=m; ++j) {
            if (i%4==1 || i%4==3 || (i%4==2 && j==m) || (i%4==0 && j==1)) {
                x+='#';
            } else {
                x+='.';
            }
        }
        cout << x;
        nl;
    }
}