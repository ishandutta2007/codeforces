#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
    int n, x=0, y=0, z=0;
    cin >> n;
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        x+=a; y+=b; z+=c;
    }
    if(x==0 && y==0 && z==0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}