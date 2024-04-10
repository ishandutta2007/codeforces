#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

const int MAXN = 100010;

vector <int> g[MAXN];
vector <pair <int, int> > f;
int ans = 0;
int d[MAXN];

void calc_h(int v, int h) {
    d[v] = h;
    ans = max(ans, h);
    for (int i = 0; i < (int) g[v].size(); i++) {
        int to = g[v][i];
        calc_h(to, h + 1);
    }
}

int main() {
    int n, d, h;
    cin >> n >> d >> h;
    if (2 * h < d || d == 1 && n > 2) {
        cout << -1 << endl;
        return 0;
    } else if (h == d) {   
        if (h == n - 1) {
            for (int i = 2; i <= n; i++) {
                cout << i - 1 << " " << i << endl;
            }
            return 0;
        } 
    } 
    int cur = 2;
    int cnt = 0;
    int count = 0;
    while (cnt < h) {
        f.push_back(mp(cur - 1, cur));
        g[cur - 1].push_back(cur);
        cur++;
        cnt++;
        count++;
    }
    cnt = 0;
    while (cnt < d - h) {
        if (cnt == 0) {
            f.push_back(mp(1, cur));
            g[1].push_back(cur);
        } else {
            f.push_back(mp(cur - 1, cur));
            g[cur - 1].push_back(cur);
        }
        cnt++;
        cur++;
        count++;
    }
    while (count < n - 1) {
        f.push_back(mp(h, cur));
        g[h].push_back(cur);
        cur++;
        count++;
    }
    calc_h(1, 0);
    if (ans != h || (int) f.size() != n - 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < (int) f.size(); i++) {
        cout << f[i].first << " " << f[i].second << endl;
    }
}