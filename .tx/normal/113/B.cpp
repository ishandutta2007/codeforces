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

bool ss[2222];
bool ee[2222];

lint p1 = 31;
lint h1[2222];
lint M1 = 1e9 + 7;
lint pow1[2222];

lint p2 = 239;
lint h2[2222];
lint M2 = 1e9 + 9;
lint pow2[2222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scids(a, s, e);
    int n = a.size();
    if (s.size() > n || e.size() > n) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * p1 + a[i] - 'a' + 1) % M1;
        h2[i + 1] = (h2[i] * p2 + a[i] - 'a' + 2) % M2;
    }

    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < 2222; i++) {
        pow1[i] = pow1[i - 1] * p1 % M1;
        pow2[i] = pow2[i - 1] * p2 % M2;
    }

    for (int i = 0; i + s.size() <= n; i++) {
        ss[i] = s == a.substr(i, s.size());
    }
    for (int i = 0; i + e.size() <= n; i++) {
        ee[i] = e == a.substr(i, e.size());
    }

    vector<pair<lint, lint> > hs;

    for (int i = 0; i < n; i++) {
        if (ss[i]) {
            for (int j = 0; j < n; j++) {
                if (ee[j] && i <= j && i + s.size() <= j + e.size()) {
                    lint x = (h1[j + 1] - h1[i] * pow1[j - i + 1] + M1 * M1) % M1;
                    lint y = (h2[j + 1] - h2[i] * pow2[j - i + 1] + M2 * M2) % M2;
//                    if (hs.find({x, y}) == hs.end()) {
                        hs.push_back({x, y});
//                        cout << i << " " << j << endl;
//                        cout << a.substr(i, j - i + 1) << endl;
//                    }
                }
            }
        }
    }

    sort(hs.begin(), hs.end());
    cout << unique(hs.begin(), hs.end()) - hs.begin();

    return 0;
}