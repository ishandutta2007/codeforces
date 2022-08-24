#include <bits/stdc++.h>
#define mp make_pair
#define fc first
#define sc second

using namespace std;

typedef long long ll;

string to_str(int n) {
    string p = "";
    while (n > 0) {
        p += (n % 10 + '0');
        n /= 10;
    }
    reverse(p.begin(), p.end());
    return p;
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++) {
        s += to_str(i);
        if (s.size() >= n) {
            cout << s[n - 1] << endl;
            return 0;
        }
    }
}