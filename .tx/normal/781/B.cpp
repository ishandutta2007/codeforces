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

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

pair<string, string> a[1111];
string ans[1111];
bool ww[1111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    map<string, int> c;
    for (int i = 0; i < n; i++) {
        scids(s, t);
        a[i].first = s.substr(0, 3);
        a[i].second = s.substr(0, 2) + t[0];
        c[a[i].first]++;
    }

    set<string> tk;
    int done = 0;
    for (int i = 0; i < n; i++) {
        if (c[a[i].first] > 1) {
            ans[i] = a[i].second;
            tk.insert(a[i].second);
            done++;
            ww[i] = true;
        }
    }
    bool changed = true;
    while (done < n && changed) {
        changed = false;
        for (int i = 0; i < n; i++) {
            if (ww[i]) {
                continue;
            }
            if (tk.find(a[i].first) != tk.end()) {
                ans[i] = a[i].second;
                tk.insert(a[i].second);
                ww[i] = true;
                changed = true;
                done++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!ww[i]) {
            ans[i] = a[i].first;
            tk.insert(a[i].first);
        }
    }

    if (tk.size() != n) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}