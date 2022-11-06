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

vector<int> g[111111];
int c[111111];
int d[111111];

int get_dc(int v, int p, int cc) {
    if (c[v] != cc) {
        return v;
    }
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        int t;
        if ((t = get_dc(i, v, cc)) != -1) {
            return t;
        }
    }
    return -1;
}

bool same_c(int v, int p, int cc) {
    if (c[v] != cc) {
        return false;
    }
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (!same_c(i, v, cc)) {
            return false;
        }
    }
    return true;
}

bool is_ok(int p) {
    for (int i : g[p]) {
        if (!same_c(i, p, c[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++;
        d[y]++;
    }
    
    set<int> cs;
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        cs.insert(c[i]);
    }
    
    if (cs.size() == 1) {
        cout << "YES\n1";
        return 0;
    }
    
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            p = i;
            break;
        }
    }
    
    p = get_dc(p, -1, c[p]);
    if (is_ok(p)) {
        cout << "YES\n";
        cout << p + 1;
        return 0;
    }
    for (int i : g[p]) {
        if (c[i] != c[p]) {
            if (is_ok(i)) {
                cout << "YES\n";
                cout << i + 1;
                return 0;
            }
            break;
        }
    }
    
    cout << "NO";

    return 0;
}