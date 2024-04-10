#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a, b, c, d;
string s[2] = {"Tidak", "Ya"};

void solve() {
    cin >> a >> b >> c >> d;
    cout << s[(a+b)%2 == 1 && (a|d)] << " ";
    cout << s[(a+b)%2 == 1 && (b|c)] << " ";
    cout << s[(a+b)%2 == 0 && (b|c)] << " ";
    cout << s[(a+b)%2 == 0 && (a|d)] << endl;
}


int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}