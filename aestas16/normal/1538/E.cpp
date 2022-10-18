/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

struct Node {
    string pre, suf;
    int cnt;
};
map<string, Node> qwq;
string var, s1, opt, s2;

int calc(string str) {
    int ret = 0;
    for (int i = 0; i + 3 < str.size(); i++)
        if (str.substr(i, 4) == "haha") ret++;
    return ret;
}

Node merge(Node u, Node v) {
    string pre = u.pre + v.pre, suf = u.suf + v.suf;
    if (pre.size() > 3) pre = pre.substr(0, 3);
    if (suf.size() > 3) suf = suf.substr(suf.size() - 3, 3);
    return (Node){pre, suf, u.cnt + v.cnt + calc(u.suf + v.pre)};
}
Node setval(string str) {
    Node ret;
    for (int i = 0; i < str.size(); i++) {
        if (i < 3) ret.pre += str[i];
        if (i + 3 >= str.size()) ret.suf += str[i];
    }
    ret.cnt = calc(str);
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        qwq.clear();
        for (int i = 1; i <= n; i++) {
            cin >> var >> opt >> s1;
            if (opt[0] == ':') qwq[var] = setval(s1);
            else cin >> opt >> s2, qwq[var] = merge(qwq[s1], qwq[s2]);
        }
        printf("%lld\n", qwq[var].cnt);
    }
    return 0;
}