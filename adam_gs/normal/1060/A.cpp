#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int w=0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='8') {
            ++w;
        }
    }
    cout << min(w, n/11);
}