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


int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m);
    for (int im = 0; im < m; im++) {
        scid(k);
        bool ok = false;
        map<int, set<int>> a;
        for (int i = 0; i < k; ++i) {
            scid(x);
            int y = abs(x);
            a[y].insert(x);
            if (a[y].size() == 2) {
                ok = true;
            }
        }
        if (!ok) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}