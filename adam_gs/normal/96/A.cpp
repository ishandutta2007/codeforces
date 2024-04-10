#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
    string x;
    cin >> x;
    int l = 1;
    rep(i, x.size()-1) {
        if (x[i]==x[i+1]) {
            ++l;
        } else {
            l=1;
        }
        if(l>=7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}