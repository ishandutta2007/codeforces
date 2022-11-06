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

string ans[111111];
string ps[3] = {"popStack", "popQueue", "popFront"};
string as[3] = {"pushStack", "pushQueue", "pushFront"};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    set<pair<int, int> > s;
    int lst = -1;
    int cur = -1;
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x == 0) {
            int k = min((int) s.size(), 3);
            auto it = s.rbegin();
            for (int i = 0; i < k; i++) {
                ans[it->second] = as[i];
                ++it;
            }
            for (int i = k; i < s.size(); i++) {
                ans[it->second] = "pushBack";
                it++;
            }

            for (int i = lst + 1; i <= cur; i++) {
                cout << ans[i] << "\n";
            }

            cout << k;
            for (int i = 0; i < k; i++) {
                cout << " " << ps[i];
            }
            cout << "\n";
            s.clear();
            lst = cur;
        } else {
            s.insert({x, ++cur});
        }
    }

    for (int i = lst + 1; i <= cur; i++) {
        cout << "pushBack" << "\n";
    }

    return 0;
}