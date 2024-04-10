#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

map<int, long long> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int foo;
        cin >> foo;
        mp[foo - i] += foo;
    }
    long long mx = 0;
    for (auto e : mp) {
        mx = max(mx, e.y);
    }
    cout << mx;
    return 0;
}