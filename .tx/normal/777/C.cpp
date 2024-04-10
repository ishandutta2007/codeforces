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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m);
    vector<vector<int> > a(n, vector<int>(m));
    vector<vector<int> > b(n, vector<int>(m));
    vector<int> mx(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sci(a[i][j]);
        }
    }

    for (int j = 0; j < m; j++) {
        int i = 0;
        while (i < n) {
            int x = i;
            while (x + 1 < n && a[x][j] <= a[x + 1][j]) {
                x++;
            }
            while (i <= x) {
                b[i][j] = x;
                i++;
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << b[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for (int i = 0; i < n; i++) {
        mx[i] = b[i][0];
        for (int j = 1; j < m; j++) {
            mx[i] = max(mx[i], b[i][j]);
        }
    }

    scid(k);
    while (k-- > 0) {
        scid(l, r);
        --l; --r;
        if (mx[l] >= r) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << "\n";
    }

    return 0;
}