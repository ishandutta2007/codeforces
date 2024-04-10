#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    n = n / 9 + 1;
    for (int i = 1; i <= n; i++) cout << 9;
    for (int i = 1; i <= n - 1; i++) cout << 0;
    cout << "1\n";
    for (int i = 1; i <= n; i++) cout << 9;
    return 0;
}