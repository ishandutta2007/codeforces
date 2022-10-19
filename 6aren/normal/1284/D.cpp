#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define iii pair<ii, int>
#define x first.first
#define y first.second
#define z second

const int N = 100005;

struct BIT {
    vector<int> bit;
    int maxn;
    
    BIT(int n) {
        bit.resize(n + 2, 0);
        maxn = n + 1;
    }

    void update(int k, int val) {
        for (int i = k; i < maxn; i += (i & (-i))) {
            bit[i] += val;
        }
    }

    int get(int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    }
};

int n;
vector<iii> a, b;
ii aa[N], bb[N];
int t[4 * N];
int it[4 * N];

void update(int k, int val) {
    for (int i = k; i < 4 * N; i += (i & (-i))) {
        it[i] = max(it[i], val);
    }
}

int get(int k) {
    int mx = 0;
    for (int i = k; i > 0; i -= (i & (-i))) {
        mx = max(mx, it[k]);
    }
    return mx;
}

struct cmp {
    bool operator() (iii u, iii v) {
        return u.y > v.y;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    set<int> s;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int sa, ea, sb, eb;
        cin >> sa >> ea >> sb >> eb;
        s.insert(sa);
        s.insert(ea);
        s.insert(sb);
        s.insert(eb);
        a.pb({{sa, ea}, i});
        b.pb({{sb, eb}, i});
        aa[i] = {sa, ea};
        bb[i] = {sb, eb};
    }
    int comp = 0;
    for (auto u : s) {
        comp++;
        mp[u] = comp;
    }
    for (auto &e : a) {
        e.x = mp[e.x];
        e.y = mp[e.y];
    }
    for (auto &e : b) {
        e.x = mp[e.x];
        e.y = mp[e.y];
    }
    for (ii &e : aa) {
        e.first = mp[e.first];
        e.second = mp[e.second];
    }
    for (ii & e : bb) {
        e.first = mp[e.first];
        e.second = mp[e.second];
    }
    sort(all(a));
    sort(all(b));
    BIT bit = BIT(4 * n);
    priority_queue<iii, vector<iii>, cmp> pq;
    bool flag = 0;
    for (auto e : a) {
        int xx = e.x;
        int yy = e.y;
        int id = e.z;
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            if (u.y < xx) {
                ii o = bb[u.z];
                bit.update(o.first, 1);
                bit.update(o.second, 1);
                update(o.first, o.second);
            } else {
                pq.push(u);
                break;
            }
        }
        auto u = bb[id];
        xx = u.first;
        yy = u.second;
        if (get(xx - 1) > yy) {
            flag = 1;
            break;
        }
        if (bit.get(yy) - bit.get(xx - 1) > 0) {
            flag = 1;
            break;
        }
        pq.push(e);
    }
    bit = BIT(4 * n);
    while (!pq.empty()) pq.pop();
    memset(it, 0, sizeof(it));
    for (auto e : b) {
        int xx = e.x;
        int yy = e.y;
        int id = e.z;
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            if (u.y < xx) {
                ii o = aa[u.z];
                bit.update(o.first, 1);
                bit.update(o.second, 1);
                update(o.first, o.second);
            } else {
                pq.push(u);
                break;
            }
        }
        auto u = aa[id];
        xx = u.first;
        yy = u.second;
        if (get(xx - 1) > yy) {
            flag = 1;
            break;
        }
        if (bit.get(yy) - bit.get(xx - 1) > 0) {
            flag = 1;
            break;
        }
        pq.push(e);
    }
    if (flag == 1) cout << "NO";
    else cout << "YES";
    return 0;
}