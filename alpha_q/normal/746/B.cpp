#include <bits/stdc++.h>
 
using namespace std;

int n;
string s;
deque <char> d;

int main (int argc, char const *argv[]) {
    cin >> n >> s;
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            if (i & 1) d.push_front(s[i]);
            else d.push_back(s[i]);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (i & 1) d.push_back(s[i]);
            else d.push_front(s[i]);
        }
    }
    for (int i = 0; i < n; ++i) cout << d[i];
    cout << '\n';
    return 0;
}