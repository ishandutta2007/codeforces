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

string a[555555];
int len[555555];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        len[i] = a[i].size();
    }

    int ans = 0;

    for (int i = n - 2; i >= 0; i--) {
        int p = -1;
        for (int j = 0; j < min(len[i], len[i + 1]); j++) {
            if (a[i][j] != a[i + 1][j]) {
                p = j;
                break;
            }
        }
        if (p == -1) {
            ans += max(0, len[i] - len[i + 1]);
            len[i] = min(len[i], len[i + 1]);
        } else if (a[i][p] > a[i + 1][p]) {
            ans += len[i] - p + 1;
            len[i] = p;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len[i]; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}