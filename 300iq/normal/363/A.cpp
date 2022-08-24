#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair

string s[10];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    s[0] = "O-|-OOOO";
    s[1] = "O-|O-OOO";
    s[2] = "O-|OO-OO";
    s[3] = "O-|OOO-O";
    s[4] = "O-|OOOO-";
    s[5] = "-O|-OOOO";
    s[6] = "-O|O-OOO";
    s[7] = "-O|OO-OO";
    s[8] = "-O|OOO-O";
    s[9] = "-O|OOOO-";
    int n;
    cin >> n;
    if (!n) {
        cout << s[0] << endl;
        return 0;
    }
    while (n > 0) {
        cout << s[n % 10] << endl;
        n /= 10;
    }
}