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

    scids(s);
    int xz = 0;
    while (xz < s.size() && s[xz] == '0') {
        xz++;
    }
    if (xz == s.size()) {
        cout << 0;
        return 0;
    }
    s = s.substr(xz, s.size() - xz);
    auto p = s.find('.');
    if (p == string::npos) {
        if (s.size() == 1) {
            cout << s;
            return 0;
        }
        s += '.';
    }

    string ans = "";
    int cb = -1;
    int ad = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ad = 0;
        } else {
            cb += ad;
            ans += s[i];
        }
    }

    xz = 0;
    while (xz < ans.size() && ans[xz] == '0') {
        xz++;
        cb--;
    }
    ans = ans.substr(xz, ans.size() - xz);
    string t = "";
    ans = t + ans[0] + '.' + ans.substr(1, ans.size() - 1);

    while (ans.back() == '0') {
        ans.pop_back();
    }
    if (ans.back() == '.') {
        ans.pop_back();
    }

    if (cb == 0) {
        cout << ans;
    } else {
        ans += "E";
        cout << ans << cb;
    }

    return 0;
}