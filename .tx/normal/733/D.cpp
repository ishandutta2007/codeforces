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

int a[111111][3];
map<pair<int, int>, vector<pair<int, int> >> mx;

pair<int, int> get(int x, int y, int z, int id) {
    auto& a = mx[{x, y}];
    if (a.size() == 1) {
        return {-1, -1};
    }
    if (a[0].second == id) {
        return a[1];
    }
    return a[0];
}

int mn(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i][0], a[i][1], a[i][2]);
        sort(a[i], a[i] + 3);
        mx[{a[i][0], a[i][1]}].push_back({a[i][2], i});
        mx[{a[i][0], a[i][2]}].push_back({a[i][1], i});
        mx[{a[i][1], a[i][2]}].push_back({a[i][0], i});
    }

    for (auto& i : mx) {
        sort(i.second.rbegin(), i.second.rend());
    }

    int mxr = -1;
    int ak = -1;
    int a1 = -1;
    int a2 = -1;

    for (int i = 0; i < n; i++) {
        auto& x = a[i];

        int tt = mn(x[0], x[1], x[2]);
        if (tt > mxr) {
            mxr = tt;
            ak = 1;
            a1 = i;
        }

        auto b = get(x[0], x[1], x[2], i);
        if (b.first != -1) {
            int ta = min(x[0], min(x[1], b.first + x[2]));
            if (ta > mxr) {
                mxr = ta;
                ak = 2;
                a1 = i;
                a2 = b.second;
            }
        }

        b = get(x[1], x[2], x[0], i);
        if (b.first != -1) {
            int ta = min(x[1], min(x[2], b.first + x[0]));
            if (ta > mxr) {
                mxr = ta;
                ak = 2;
                a1 = i;
                a2 = b.second;
            }
        }

        b = get(x[0], x[2], x[1], i);
        if (b.first != -1) {
            int ta = min(x[0], min(x[2], b.first + x[1]));
            if (ta > mxr) {
                mxr = ta;
                ak = 2;
                a1 = i;
                a2 = b.second;
            }
        }
    }

    cout << ak << "\n" << a1 + 1 << " ";
    if (ak == 2) {
        cout << a2 + 1;
    }


    return 0;
}