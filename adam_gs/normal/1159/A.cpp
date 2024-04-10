#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mi=0, l=0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='-') {
            --l;
        } else {
            ++l;
        }
        mi=min(mi, l);
    }
    cout << abs(mi-l);
}