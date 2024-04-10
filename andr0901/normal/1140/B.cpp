#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        string s;
        cin >> n >> s;
        int i = 0;
        for (; i < n; i++)
            if (s[i] == '>')
                break;
        int j = n - 1;
        for (; j >= 0; j--)
            if (s[j] == '<')
                break;
        cout << min(i, (int)s.size() - 1 - j) << "\n";
    }
    return 0;
}