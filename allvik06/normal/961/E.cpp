#include <bits/stdc++.h>

using namespace std;
#define int long long
struct trio {
    int x, i, flag, y;
};

bool cmp(trio a, trio b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.flag < b.flag;
}

vector <int> f;

void add(int i, int x, int n) {
    while (i < n) {
        f[i] += x;
        i = (i | (i + 1));
    }
}

int get(int i) {
    int res = 0;
    while (i >= 0) {
        res += f[i];
        i = (i & (i + 1)) - 1;
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <trio> b;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        /*if (a[i] >= i + 1) {
            --sum;
        }*/
    }
    vector <int> c = a;
    for (int i = 0; i < n; ++i) {
        c.push_back(i + 1);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    unordered_map <int, int> d;
    for (int i = 0; i < c.size(); ++i) {
        d[c[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = d[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        b.push_back({i, i, 0, a[i]});
        b.push_back({a[i], i, 1, a[i]});
    }
    sort(b.rbegin(), b.rend(), cmp);
    f.resize(c.size());
    for (int i = 0; i < b.size(); ++i) {
        if (b[i].flag == 1) {
            add(b[i].i, 1, c.size());
        }
        else {
            sum += get(min(b[i].i - 1, b[i].y));
        }
    }
    cout << sum;
    return 0;
}