#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int a[N], b[N], p[N];
bool check[N];
int n, t;

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] < i) return cout << "No", 0;
        if (p[i] > p[i - 1] && p[i - 1] != i - 1) return cout << "No", 0;
        if (p[i] < p[i - 1]) return cout << "No", 0;
        check[p[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) b[i] = a[i] + t;
        else b[i] = a[i + 1] + t;
        if (b[i] == b[i - 1]) b[i]++;
    }
    if (b[n] == b[n - 1]) b[n]++;
    for (int i = 1; i < n; i++) {
        if (check[i] && b[i] >= a[i + 1] + t) return cout << "No", 0;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    return 0;
}