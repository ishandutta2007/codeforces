#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


vector<int> z_f(string t) {
    int n = t.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (r > i) {
            z[i] = min(r - i, z[i - l]);
        }
        for (; i + z[i] < n && t[i + z[i]] == t[z[i]]; z[i]++);
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

pair<int,int> count(string s) {
    int c0 = 0, c1 = 0;
    for (auto ch: s) {
        c0 += ch == '0';
        c1 += ch == '1';
    }
    return {c0, c1};
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    string s, t;
    cin >> s;
    cin >> t;
    auto s01 = count(s);
    auto z = z_f(t);
    int best = t.size();
    for (int i = 1; i < sz(t); i++) {
        assert(z[i] + i <= sz(t));
        if (z[i] + i == sz(t)) {
           best = i;
           break;
        }
    }
    string add = t.substr(t.size() - best);

    auto t01 = count(t);
    auto suft01 = count(add);

    int answer = -1;
    int r0 = -1, r1 = -1;
    for (int i = 0; ;i++) {
        int u0 = 0;
        int u1 = 0;
        if (i > 0) {
            u0 += t01.F;
            u1 += t01.S;
            u0 += suft01.F * (i - 1);
            u1 += suft01.S * (i - 1);
        }
        if (u0 <= s01.F && u1 <= s01.S) {
            answer = i;
            r0 = s01.F - u0;
            r1 = s01.S - u1;
        }
        else {
            break;
        }
    }
    assert(answer != -1);

//    vector<int> ret(s.size(), -1);
    string ret;
    if (answer > 0) {
        ret += t;
        for (int i = 0; i < answer - 1; i++) {
            ret += add;
        }
    }
    for (; r0 > 0; r0--) ret += "0";
    for (; r1 > 0; r1--) ret += "1";
    assert(ret.size() == s.size());

    cout << ret << endl;
//    db(answer);


    return 0;
}