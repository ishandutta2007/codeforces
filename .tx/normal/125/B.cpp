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

void prsp(int h) {
    for (int i = 0; i < h; i++) {
        cout << "  ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    scids(s);
    int ch = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i + 1] != '/') {
            prsp(ch);
            cout << s.substr(i, 3) << "\n";
            ch++;
            i += 2;
        } else {
            --ch;
            prsp(ch);
            cout << s.substr(i, 4) << "\n";
            i += 3;
        }
    }



    return 0;
}