#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

int parse(string a) {
    int ans = 10 * (a[0] - '0') + (a[1] - '0');
    ans = 60 * ans + 10 * (a[3] - '0') + (a[4] - '0');
    //cout << a << " " << ans << "\n";
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    int x = parse(a), y = parse(b);
    if (y < x)
        y += 60 * 24;
    int z = ((x + y) / 2) % (60 * 24);
    //cout << x << " " << y << " " << z << "\n";
    if (z / 60 < 10)
        cout << '0';
    cout << z / 60 << ":";
    if (z % 60 < 10)
        cout << '0';
    cout << z % 60;
    return 0;
}