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

int ans[5555];

int req(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);

    int x = req(0, 1);
    int y = req(0, 2);
    int z = req(1, 2);

    ans[1] = (x - y + z) / 2;
    ans[2] = z - ans[1];
    ans[0] = x - ans[1];

    for (int i = 3; i < n; i++) {
        int r = req(0, i);
        ans[i] = r - ans[0];
    }

    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}