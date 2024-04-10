#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long x=0;
    while (n--){
        string s;
        cin >> s;
        if (s[1]=='-') {
            --x;
        } else {
            ++x;
        }
    }
    cout << x;
}