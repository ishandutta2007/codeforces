#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

vector<int> g[1111111];

pair<lint, lint> hs(vector<int>& a) {
    sort(a.begin(), a.end());
    lint h1 = 0;
    lint h2 = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        h1 = h1 * 31 + (a[i] + 1) ^ (i + 239);
        h2 = h2 * 239 + (a[n - 1 - i] + 1) ^ (i + 31);
    }
    return make_pair(h1, h2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    map<pair<lint, lint>, int > m1, m2;
    
    for (int i = 0; i < n; i++) {
        m1[hs(g[i])]++;
        g[i].push_back(i);
        m2[hs(g[i])]++;
    }
    
    lint ans = 0;
    for (auto& i : m1) {
        ans += 1LL * i.second * (i.second - 1) / 2;
    }
    
    for (auto& i : m2) {
        ans += 1LL * i.second * (i.second - 1) / 2;
    }
    
    cout << ans;
    

    return 0;
}