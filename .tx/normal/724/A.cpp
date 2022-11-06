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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    map<string, int> m;
    m["monday"] = 0;
    m["tuesday"] = 1;
    m["wednesday"] = 2;
    m["thursday"] = 3;
    m["friday"] = 4;
    m["saturday"] = 5;
    m["sunday"] = 6;

    scids(s, t);

    int x = m[s];
    int y = m[t];

    int d = (y - x + 7) % 7;
    if (d == 3 || d == 2 || d == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}