#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int INF = 1e9;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> amt(n);
    vector<vector<int>> loc(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        a[i]--;
        amt[a[i]]++;
        loc[a[i]].push_back(i);
    }

    pair<int, int> best = {-1, -1};
    for (int i = 0; i < n; i++) {
        best = max(best, {amt[i], i});
    }

    sort(amt.begin(), amt.end());
    if (amt.back() == n) {
        cout << 0 << '\n'; 
        return 0;
    } else if (amt[n - 1] == amt[n - 2]) {
        cout << n << '\n';
        return 0;
    }

    int must = best.second;
    vector<int> le(n);
    vector<int> ri(n);
    int rec = -1;
    for (int i = 0; i < n; i++) {
        le[i] = rec;
        if (a[i] == must) 
            rec = i;
    }
    rec = n;
    for (int i = n - 1; i >= 0; i--) {
        ri[i] = rec;
        if (a[i] == must) 
            rec = i;
    }

    vector<int> pre(n);
    for (int i = 0; i < n; i++) 
        pre[i] = (i ? pre[i - 1] : 0) + (a[i] == must);

    set<int> unmarked; 
    for (int i = 0; i < n; i++) 
        if (a[i] == must) 
            unmarked.insert(i);
    
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (i == must) 
            continue;

        vector<int> marked;
        vector<int> possible;
        for (int x : loc[i]) {
            possible.push_back(x);
            auto it = unmarked.lower_bound(x);
            if (it != unmarked.end()) {
                int val = *it;
                marked.push_back(val);
                unmarked.erase(val);
                possible.push_back(val);
            }
            it = unmarked.lower_bound(x);
            if (it != unmarked.begin()) {
                it = prev(it);
                int val = *it;
                marked.push_back(val);
                unmarked.erase(val);
                possible.push_back(val);
            }
        }

        sort(possible.begin(), possible.end());
        possible.erase(unique(possible.begin(), possible.end()), possible.end());

        map<int, int> mp;
        int num = (int) possible.size();
        int run = 0;
        for (int j = 0; j < num; j++) {
            int x = possible[j];
            int cloc = le[x] + 1;
            if (j)
                cloc = max(cloc, possible[j - 1] + 1);
            int prefix = run;
            if (cloc > 0) 
                prefix -= pre[cloc - 1];
            if (mp.find(prefix) == mp.end())
                mp[prefix] = cloc - 1;

            run += (a[x] == i);
            int cur = run - pre[x];
            int extend = ri[x] - 1;
            if (j != num - 1)
                extend = min(extend, possible[j + 1] - 1);
            if (mp.find(cur) != mp.end()) {
                ans = max(ans, extend - mp[cur]);
            }
        }
        for (int m : marked) 
            unmarked.insert(m);
    }
    cout << ans << '\n';    
    return 0;
}