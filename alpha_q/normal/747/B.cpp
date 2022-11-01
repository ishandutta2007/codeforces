#include <bits/stdc++.h>
 
using namespace std;

int main (int argc, char const *argv[]) {
    int n; string s;
    int a = 0, c = 0, g = 0, t = 0;
    cin >> n >> s;
    if (n % 4) {
        cout << "===\n";
        return 0;
    }
    int each = n/4;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') ++a;
        if (s[i] == 'C') ++c;
        if (s[i] == 'G') ++g;
        if (s[i] == 'T') ++t;
    }
    if (a > each or c > each or g > each or t > each) {
        cout << "===\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (a < each) s[i] = 'A', ++a;
            else if (c < each) s[i] = 'C', ++c;
            else if (g < each) s[i] = 'G', ++g;
            else if (t < each) s[i] = 'T', ++t;
        }
    }
    cout << s << '\n';
    return 0;
}