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

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    for (int i = 0; i < s.size(); i++) {
        if (i + 2 < s.size() && s.substr(i, 3) == "ogo") {
            int j = i + 3;
            while (j + 1 < s.size() && s[j] == 'g' && s[j + 1] == 'o') {
                j += 2;
            }
            i = j - 1;
            cout << "***";
        } else {
            cout << s[i];
        }
    }

    return 0;
}