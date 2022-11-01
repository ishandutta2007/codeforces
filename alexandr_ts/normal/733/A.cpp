#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
const int N = 1e5;
const int INF = 2e9;

bool gl(char c) {
    if (c == 'A') return true;
    if (c == 'U') return true;
    if (c == 'I') return true;
    if (c == 'O') return true;
    if (c == 'E') return true;
    if (c == 'Y') return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    s += 'A';
    int ans = -INF;
    int prev = -1;
    for (int i = 0; i < (int)s.size(); i++)
        if (gl(s[i]))
            ans = max(i - prev, ans), prev = i;
    cout << ans;
}