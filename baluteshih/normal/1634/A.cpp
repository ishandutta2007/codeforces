#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, flag = 1;
        string s;
        cin >> n >> k >> s;
        for (int i = 0; i < SZ(s); ++i)
            if (s[i] != s[SZ(s) - i - 1])
                flag = 0;
        if (!flag && k > 0)
            cout << "2\n";
        else
            cout << "1\n";
    }
}