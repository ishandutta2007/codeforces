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

vector<int> wh[1111111];
map<int, int> hm[1111111];

const int M = 1e9 + 7;
lint ft[1111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        scid(x);
        for (int j = 0; j < x; j++) {
            scid(y);
            --y;
            wh[y].push_back(i);
            hm[i][y]++;
        }
    }
    
    map<pair<lint, lint>, int> a;
    for (int i = 0; i < m; i++) {
        lint h1 = 0;
        lint h2 = 0;
        for (int j : wh[i]) {
            h1 = h1 * 239 + j * 31 + hm[j][i];
            h2 = (h2 * 31 + hm[j][i] * 239 + j) % M;
        }
        a[{h1, h2}]++;
    }
    
    ft[0] = 1;
    for (int i = 1; i <= m; i++) {
        ft[i] = ft[i - 1] * i % M;
    }
    
    lint ans = 1;
    for (auto p : a) {
        ans = ans * ft[p.second] % M;
    }
    
    cout << ans;
    

    return 0;
}