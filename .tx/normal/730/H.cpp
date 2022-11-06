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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

string fs[111];
set<char> cs[111];
bool bad[111];
set<int> lens;

char ans[111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(fs[i]);
    }

    for (int i = 0; i < m; i++) {
        scid(x);
        --x;
        bad[x] = true;
        lens.insert(fs[x].size());
        for (int i = 0; i < fs[x].size(); i++) {
            cs[i].insert(fs[x][i]);
        }
    }

    if (lens.size() > 1) {
        cout << "No";
        return 0;
    }

    int len = *lens.begin();

    for (int j = 0; j < len; j++) {
        if (cs[j].size() > 1) {
            ans[j] = '?';
        } else {
            ans[j] = *(cs[j].begin());
        }
    }

    for (int i = 0; i < n; i++) {
        if (!bad[i] && fs[i].size() == len) {
            bool fits = true;
            for (int j = 0; j < len; j++) {
                if (ans[j] != '?' && fs[i][j] != ans[j]) {
                    fits = false;
                }
            }
            if (fits) {
                cout << "No";
                return 0;
            }
        }
    }

    puts("Yes");
    puts(ans);

    return 0;
}