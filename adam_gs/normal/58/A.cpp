#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
    string s, x="hello";
    cin >> s;
    int l = 0;
    rep(i, s.size()) {
        if(s[i]==x[l]) ++l;
        if(l==x.size()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}