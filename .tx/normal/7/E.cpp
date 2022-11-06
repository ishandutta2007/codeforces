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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

enum Op {
    NONE, SUM, MUL
};

struct expr {
    Op op;
    bool broken;
    bool isMacro;
};

map<string, expr> defs;

expr parse(string& s, int l, int r, bool topParse = false) {
    while (s[l] == ' ') {
        l++;
    }
    while (s[r - 1] == ' ') {
        r--;
    }
    int b = 0;
    expr res = expr{NONE, false, topParse};

    vector<expr> es;
    vector<char> ss;

    int pop = l;

    for (int i = l; i < r; i++) {
        if (s[i] == '(') {
            b++;
        } else if (s[i] == ')') {
            b--;
        } else if (b == 0 && (s[i] == '+' || s[i] == '-')) {
            expr x = parse(s, pop, i);
            es.push_back(x);
            pop = i + 1;
            ss.push_back(s[i]);
        }
    }

    if (!es.empty()) {
        es.push_back(parse(s, pop, r));
        for (int i = 0; i + 1 < es.size(); i++) {
            res.broken |= es[i].broken;
            if (ss[i] == '-' && es[i + 1].isMacro && es[i + 1].op == SUM) {
                res.broken = true;
            }
        }
        res.op = SUM;
        res.broken |= es.back().broken;
        return res;
    }

    for (int i = l; i < r; i++) {
        if (s[i] == '(') {
            b++;
        } else if (s[i] == ')') {
            b--;
        } else if (b == 0 && (s[i] == '*' || s[i] == '/')) {
            expr x = parse(s, pop, i);
            es.push_back(x);
            pop = i + 1;
            ss.push_back(s[i]);
        }
    }

    if (!es.empty()) {
        es.push_back(parse(s, pop, r));
        for (int i = 0; i + 1 < es.size(); i++) {
            res.broken |= es[i].broken;
            if (es[i].op == SUM || es[i + 1].op == SUM) {
                res.broken = true;
            }
            if (ss[i] == '/' && es[i + 1].isMacro && es[i + 1].op != NONE) {
                res.broken = true;
            }
        }
        res.op = MUL;
        res.broken |= es.back().broken;
        return res;
    }

    if (s[l] == '(' && s[r - 1] == ')') {
        expr x = parse(s, l + 1, r - 1);
        if (x.broken) {
            res.broken = true;
        }
        return res;
    }

    string name = s.substr(l, r - l);
    if (defs.count(name)) {
        expr x = defs[name];
        if (x.broken) {
            res.broken = true;
        }
        res.op = x.op;
        res.isMacro = true;
    }

    return res;
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int p = 0;
        while (s[p] != 'n') {
            p++;
        }
        p += 2;
        while (s[p] == ' ') {
            p++;
        }
        string name = "";
        while (s[p] != ' ') {
            name.push_back(s[p]);
            p++;
        }
        expr e = parse(s, p, s.size(), true);
        defs[name] = e;
    }

    getline(cin, s);
    expr e = parse(s, 0, s.size(), true);
    if (e.broken) {
        cout << "Suspicious";
    } else {
        cout << "OK";
    }

    return 0;
}