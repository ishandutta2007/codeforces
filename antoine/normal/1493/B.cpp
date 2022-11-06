#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int H, M;

map<char, char> mp = {
        {'0', '0'},
        {'1', '1'},
        {'2', '5'},
        {'5', '2'},
        {'8', '8'},
        {':', ':'},
};

string rev(string s) {
    assert(s.size() == 5);
    for(char &c: s)
        if(!mp.count(c))
            return "";
        else c = mp.at(c);
    reverse(s.begin(), s.end());

    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    return h < H && m < M ? s : "";
}


string f() {
    string s;
    cin >> H >> M >> s;

    for(int rep = 1; rep < H * M + 2; ++rep) {
        string t = rev(s);
        if(!t.empty())
            return s;

        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        if(++m == M) {
            m = 0;
            if(++h == H)
                h = 0;
        }
        string hh = to_string(h);
        if(hh.size() == 1)
            hh = '0' + hh;
        string mm = to_string(m);
        if(mm.size() == 1)
            mm = '0'+ mm;
        s = hh + ':' + mm;
    }
    assert(false);
    return "";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}