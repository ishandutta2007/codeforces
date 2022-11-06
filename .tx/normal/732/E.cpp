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

int p[222222];
int s[222222];
int a[222222];
int b[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    unordered_map<int, vector<int>> cs(3 * (n + m));
    for (int i = 0; i < n; i++) {
        scid(x);
        cs[x].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        sci(s[i]);
    }

    int au = 0;
    int ac = 0;

    memset(b, -1, sizeof(b));

    for (int tt = 0; tt <= 31; tt++) {
        for (int i = 0; i < m; i++) {
            auto it = cs.find(s[i]);
            if (it != cs.end()) {
                au += tt;
                ac++;
                a[i] = tt;
                int c = it->second.back();
                b[c] = i;

                it->second.pop_back();
                if (it->second.size() == 0) {
                    cs.erase(it);
                }
                s[i] = 0;
            }
            s[i] = (s[i] + 1) >> 1;
        }
    }

    cout << ac << " " << au << "\n";
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] + 1 << " ";
    }

    return 0;
}