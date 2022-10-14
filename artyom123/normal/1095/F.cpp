#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector <int> p, r;
vector <long long> c;
set <pair<long long, int>> s;

void create_set(int x) {
    p[x] = x;
    r[x] = 1;
    s.insert({c[x], x});
}

int find_set(int x) {
    if (p[x] == x) {
        return x;
    }
    p[x] = find_set(p[x]);
    return p[x];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (r[a] < r[b]) {
        swap(a, b);
    }
    if (c[a] <= c[b]) {
        s.erase({c[b], b});
    }
    else {
        s.erase({c[a], a});
        s.erase({c[b], b});
        s.insert({c[b], a});
        c[a] = c[b];
    }
    p[b] = a;
    if (r[a] == r[b]) {
        r[a]++;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    p.resize(n);
    r.resize(n);
    c.resize(n);
    for (auto &l : c) {
        cin >> l;
    }
    vector <pair<long long, pair<int, int>> > a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].second.first >> a[i].second.second >> a[i].first;
        a[i].second.first--;
        a[i].second.second--;
    }
    for (int i = 0; i < n; i++) {
        create_set(i);
    }
    sort(a.begin(), a.end());
    int j = 0;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        while (j < m && find_set(a[j].second.first) == find_set(a[j].second.second)) {
            j++;
        }
        long long ans1 = INF;
        int x1 = -1, y1 = -1;
        if (j < m) {
            ans1 = a[j].first;
            x1 = a[j].second.first;
            y1 = a[j].second.second;
        }
        auto now1 = *s.begin();
        s.erase(s.begin());
        auto now2 = *s.begin();
        s.insert(now1);
        if (ans1 < now1.first + now2.first) {
            ans += ans1;
            union_sets(x1, y1);
            j++;
        }
        else {
            ans += (now1.first + now2.first);
            union_sets(now1.second, now2.second);
        }
    }
    cout << ans;
    return 0;
}