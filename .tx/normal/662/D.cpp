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

map<string, int> ans;
unordered_set<string> was(300000);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int last = -1;


    for (int i = 1989; i <= 99999; i++) {
        int x = i;
        string tp = "";
        while (true) {
            tp = char(x % 10 + '0') + tp;
            x /= 10;
            if (was.find(tp) == was.end()) {
                break;
            }
        }
        was.insert(tp);

        ans[tp] = i;
    }

    vector<lint> p10(11);
    p10[0] = 1;
    for (int i = 1; i < 11; i++) {
        p10[i] = p10[i - 1] * 10;
    }

    vector<lint> fn(10);
    fn[1] = 1989;
    for (int i = 2; i < 10; i++) {
        fn[i] = fn[i - 1] + p10[i - 1];
    }

    scid(n);
    while (n-- > 0) {
        scids(s);
//        cerr << "|" << s << "|" << endl;
        s = s.substr(4, s.size() - 4);
        int x = atoi(s.c_str());
//        cerr << x << endl;
        int len = s.length();
        if (ans.find(s) != ans.end()) {
            cout << ans[s] << "\n";
        } else {
            if (x >= fn[len]) {
                cout << s << "\n";
            } else {
                cout << 1 << s << "\n";
            }
        }
    }

    return 0;
}