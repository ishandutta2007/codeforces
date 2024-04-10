#include <bits/stdc++.h>

class simple_string {
    std::string pre, suf;
    long long ans;

    static std::string get_pre(const std::string &s) {
        auto len = std::min<std::size_t>(s.size(), 3);
        return s.substr(0, len);
    }

    static std::string get_suf(const std::string &s) {
        auto len = std::min<std::size_t>(s.size(), 3);
        return s.substr(s.size() - len, len);
    }

public:
    static int calc(const std::string &s) {
        int res = 0;
        auto p = s.find("haha");
        while (p != s.npos) {
            ++res;
            p = s.find("haha", p + 1);
        }
        return res;
    }

    simple_string()
    : pre(), suf(), ans(0) {}

    simple_string(const std::string &s)
    : pre(get_pre(s)), suf(get_suf(s)), ans(calc(s)) {}

    simple_string operator+(const simple_string &rhs) const {
        simple_string res;
        res.pre = get_pre(pre + rhs.pre);
        res.suf = get_suf(suf + rhs.suf);
        res.ans = ans + rhs.ans + calc(suf + rhs.pre);
        return res;
    }

    long long count() const {
        return ans;
    }
};

void solve() {
    int q;
    std::cin >> q;
    std::map<std::string, simple_string> mp;
    while (q--) {
        std::string x, op;
        std::cin >> x >> op;
        if (op == "=") {
            std::string a, b;
            std::cin >> a >> op >> b;
            mp[x] = mp[a] + mp[b];
        } else {
            std::string s;
            std::cin >> s;
            mp[x] = s;
        }
        if (q == 0) {
            std::cout << mp[x].count() << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}