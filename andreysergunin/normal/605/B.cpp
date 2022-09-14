#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 200100;

int main() {
    int n, m;
    int a[MAXN], b[MAXN], u[MAXN], v[MAXN];
    vector< pair<int, int> > c, d;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if (b[i] == 1)
            c.push_back(make_pair(a[i], i));
        if (b[i] == 0)
            d.push_back(make_pair(a[i], i));
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    for (int i = 0; i < (int)c.size(); i++) {
        u[c[i].second] = 1;
        v[c[i].second] = i + 2;
    }
    int l = 0;
    int k = 0;
    for (int i = 0; i < (int)d.size(); i++) {
        if (k == l) {
            k = 0;
            l++;
        }
        if (c[l].first > d[i].first) {
            cout << -1;
            return 0;
        }
        else {
            u[d[i].second] = k + 2;
            v[d[i].second] = l + 2;
        }
        k++;
    }
    for (int i = 0; i < m; i++)
        cout << u[i] << " " << v[i] << endl;
}