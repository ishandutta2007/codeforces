#include <bits/stdc++.h>

#define mp make_pair 
#define endl '\n'
#define ll long long
#define fc first
#define sc second
#define mp make_pair

 
using namespace std;
 
int main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0) {
        if (a == b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    if ((b - a) % c == 0 && (b - a) / c >= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}