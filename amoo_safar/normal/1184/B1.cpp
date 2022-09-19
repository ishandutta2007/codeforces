#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, inf = 1e18;
int s[N], ps[N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    vector < pair <int, int> > v;
    for (int i = 0; i < m; i ++) {
        int d, g; cin >> d >> g;
        v.push_back({d, g});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= m; i ++) ps[i] = ps[i - 1] + v[i - 1].second;
    for (int i = 0; i < n; i ++) {
        int x = lower_bound(v.begin(), v.end(), make_pair(s[i], inf)) - v.begin();
        cout << ps[x] << " ";
    }
}