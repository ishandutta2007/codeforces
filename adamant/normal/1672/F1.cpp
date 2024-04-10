#include <bits/stdc++.h>

#define int int64_t

using namespace std;

vector<int> mysol(vector<int> a) {
    int n = a.size();
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        a[i]--;
        cnt[a[i]]++;
    }
    map<int, vector<int>, function<bool(int, int)>> pos([&](int x, int y) {
        return make_pair(cnt[x], x) > make_pair(cnt[y], y);
    });
    for(int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    vector<int> ans(n);
    int p[n];
    vector<int> cyc;
    while(!pos.empty()) {
        auto it = begin(pos);
        while(it != end(pos)) {
            cyc.push_back(it->second.back());
            it->second.pop_back();
            if(it->second.empty()) {
                it = pos.erase(it);
            } else {
                ++it;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        p[cyc[i]] = cyc[(i + 1) % n];
    }
    for(int i = 0; i < n; i++) {
        ans[i] = a[p[i]] + 1;
    }
    return ans;
}

const int maxn = 2e5 + 42;

int CNT[maxn];

int decycle(vector<int> a) {
    for(auto it: a) {
        CNT[it]++;
    }
    int m = a.size();
    vector<int> st;
    int ans = 0;
    for(int i = 0; i < 2 * m; i++) {
        if(CNT[a[i % m]] == 1) {
            continue;
        }
        while(!st.empty() && a[st.back() % m] > a[i % m]) {
            st.pop_back();
        }
        if(!st.empty() && st.back() < m && a[st.back()] == a[i % m]) {
            ans++;
        }
        st.push_back(i);
    }
    for(auto it: a) {
        CNT[it]--;
    }
    return max<int>(1, ans);
}

int maxcyc(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        a[i]--, b[i]--;
        cnt[a[i]]++;
    }
    int pa[n], pb[n];
    iota(pa, pa + n, 0);
    iota(pb, pb + n, 0);
    auto cmp = [&](vector<int> const& a) {
        return [&](int x, int y) {
            return make_pair(cnt[a[x]], a[x]) < make_pair(cnt[a[y]], a[y]);
        };
    };
    sort(pa, pa + n, cmp(a));
    sort(pb, pb + n, cmp(b));
    int dp[n];
    for(int i = 0; i < n; i++) {
        dp[pb[i]] = pa[i];
    }
    for(int i = 0; i < n; i++) {
        assert(a[dp[i]] == b[i]);
    }
    int ans = n;
    vector<int> used(n);
    vector<vector<int>> cycs;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            vector<int> cyc;
            while(!used[i]) {
                used[i] = true;
                cyc.push_back(i);
                i = dp[i];
            }
            cycs.push_back(cyc);
        }
    }
    for(auto it: cycs) {
        for(auto &jt: it) {
            jt = a[jt];
        }
        ans -= decycle(it);
    }
    return ans;
}

void solve() {
    int n;
    n = 10;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> cnt(n);
    for(auto &it: a) {
        it = rand() % n + 1;
        cin >> it;
        cnt[it - 1]++;
    }
    b = mysol(a);
    //random_shuffle(begin(b), end(b));
    for(auto &it: b) {
        cout << it << ' ';
    }
    cout << endl;
    return;
    if(maxcyc(a, b) == n - *max_element(begin(cnt), end(cnt))) {
        //cout << "AC\n";
    } else {
        assert(0);
        cout << "WA\n";
    }
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1000;
    cin >> t;
    while(t--) {
        solve();
    }
}