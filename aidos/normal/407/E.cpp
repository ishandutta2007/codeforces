#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
int n;
ll k, d;
int a[maxn];
int m;
int L[maxn];

ll t[maxn * 4];
ll ad[maxn * 4];
void build(int v, int l, int r) {
    ad[v] = 0;
    t[v] = 0;
    if(l == r) {

    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
    }
}

void push(int v, int tl, int tr) {
    if(tl == tr) return;
    t[v * 2] += ad[v];
    t[v * 2 + 1] += ad[v];
    ad[v * 2] += ad[v];
    ad[v * 2 + 1] += ad[v];
    ad[v] = 0;
}
int get(int v, int tl, int tr, int l, int r, ll k) {
    push(v, tl, tr);
    if(tl > r || l > tr) {
        return -1;
    }
    if(t[v] > k) {
        return -1;
    }
    if(tl == tr) {
        return tl;
    }
    int mid = (tl + tr)/2;
    int res = get(v * 2, tl, mid, l, r, k);
    if(res != -1) return res;
    return get(v * 2 + 1, mid + 1, tr, l, r, k);
}
void add(int v, int tl, int tr, int l, int r, ll d) {
    push(v, tl, tr);
    if(tl > r || l > tr) {
        return;
    }
    if(l <= tl && tr <= r) {
        t[v] += d;
        ad[v] += d;
        return;
    }
    int mid = (tl + tr)/2;
    add(v * 2, tl, mid, l, r, d);
    add(v * 2 + 1, mid + 1, tr, l, r, d);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
pair<int, int> calc(vector<int> b) {
    m = b.size();
    map<int, int> c;
    for(int i = 0; i < m; i++) {
        if(c.count(b[i]) == 0) {
            L[i] = 0;
        } else {
            L[i] = c[b[i]] + 1;
        }
        c[b[i]] = i;
    }
    for(int i = 1; i < m; i++) {
        L[i] = max(L[i], L[i-1]);
    }
    build(1, 0, m-1);
    vector<int> mx;
    vector<int> mi;
    pair<int, int> ans = make_pair(0, 0);
    for(int i = 0; i < m; i++) {
        while(mx.size() > 0 && b[mx.back()] < b[i]) {
            int cur = mx.back();
            mx.pop_back();
            if(mx.size() > 0) {
                add(1, 0, m-1, mx.back() + 1, cur, -b[cur]);
            } else {
                add(1, 0, m-1, 0, cur, -b[cur]);
            }
        }
        if(mx.size() > 0) {
            add(1, 0, m-1, mx.back()+1, i, b[i]);
        } else {
            add(1, 0, m-1, 0, i, b[i]);
        }
        mx.push_back(i);


        while(mi.size() > 0 && b[mi.back()] > b[i]) {
            int cur = mi.back();
            mi.pop_back();
            if(mi.size() > 0) {
                add(1, 0, m-1, mi.back() + 1, cur, b[cur]);
            } else {
                add(1, 0, m-1, 0, cur, b[cur]);
            }
        }
        if(mi.size() > 0) {
            add(1, 0, m-1, mi.back()+1, i, -b[i]);
        } else {
            add(1, 0, m-1, 0, i, -b[i]);
        }
        mi.push_back(i);
        int cnt = i - get(1, 0, m-1, L[i], i, k) + 1;
        if(ans.first < cnt) {
            ans.first = cnt;
            ans.second = i;
        }
        add(1, 0, m-1, 0, i, -1);
    }

    return ans;
}
void solve() {
    cin >> n >> k >> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mi = *min_element(a, a + n);
    for(int i = 0; i<n; i++) {
        a[i] -= mi;
    }

    pair<int, int> ans = make_pair(0, 0);
    if(d == 0) {
        int cnt = 1;

        for(int i = 1; i < n; i++) {
            if(a[i] != a[i-1]) {
                if(ans.first < cnt) {
                    ans.first = cnt;
                    ans.second = i - 1;
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if(ans.first < cnt) {
            ans.first = cnt;
            ans.second = n-1;
        }
        cout << ans.second - ans.first + 2 << " " << ans.second + 1 << "\n";
        return;
    }

    for(int i = 0; i < n; ) {
        int j = i;
        vector<int> cur;
        while(i < n && a[j] % d == a[i] % d) {
            cur.push_back(a[i]/d);
            i++;
        }
        pair<int, int> res = calc(cur);
        res.second += j;
        if(res.first > ans.first) {
            ans = res;
        }
    }

    cout << ans.second - ans.first + 2 << " " << ans.second + 1 << "\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}