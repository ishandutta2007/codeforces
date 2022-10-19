#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

ii p[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    p[n + 1] = p[1];
    if (n % 2) return cout << "NO", 0;
    bool flag = 1;
    for (int i = 1; i <= n / 2; i++) {
        ii u = {p[i + 1].x - p[i].x, p[i + 1].y - p[i].y};
        ii v = {p[i + 1 + n / 2].x - p[i + n / 2].x, p[i + 1 + n / 2].y - p[i + n / 2].y};
        ii uu = {-u.x, -u.y};
        if (u != v && uu != v) flag = 0; 
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}