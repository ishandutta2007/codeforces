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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int l[111111];
int r[111111];
int v[111111];
bool in[111111];

int ans = 0;

set<int> found;

void dfs(int i, int l, int r) {
    if (v[i] < l || v[i] > r) {
        ans++;
    } else {
        found.insert(v[i]);
    }
    if (::l[i] != -1) {
        dfs(::l[i], l, min(r, v[i]));
    }
    if (::r[i] != -1) {
        dfs(::r[i], max(l, v[i]), r);
    }
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(v[i], l[i], r[i]);
        if (l[i] != -1) {
            --l[i];
            in[l[i]] = true;
        }
        if (r[i] != -1) {
            --r[i];
            in[r[i]] = true;
        }
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (!in[i]) {
            root = i;
        }
    }

    dfs(root, -2e9, 2e9);

    ans = 0;
    for (int i = 0; i < n; i++) {
        if (found.find(v[i]) == found.end()) {
            ans++;
        }
    }
    cout << ans;


    return 0;
}