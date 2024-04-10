#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
    string x;
    cin >> x;
    rep(i, x.size()) {
        x[i]=tolower(x[i]);
        if(x[i]!='a' && x[i]!='e' && x[i]!='i' && x[i]!='o' && x[i]!='u' && x[i]!='y') {
            cout << '.' << x[i];
        }
    }
}