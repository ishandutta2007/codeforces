#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 100100

string a[M], b[M];
int n, p[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
}

bool kill() {
    string pred = "";
    string ans;
    for (int i = 0; i < n; ++i) {
        ans = max(a[p[i]], b[p[i]]);
        if (a[p[i]] > pred)
            ans = min(ans, a[p[i]]);
        if (b[p[i]] > pred)
            ans = min(ans, b[p[i]]);
        if (ans <= pred)
            return false;
        pred = ans;
    }
    return true;
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    read();
    if (kill())
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}