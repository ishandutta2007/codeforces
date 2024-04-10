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

int n, a, b, k;

int mxs(int x) {
    return x / b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n, a, b, k);
    scids(s);
    s.push_back('1');
    ++n;
    vector<pair<int, int> > lens;



    int last = -1;
    int rest = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            lens.push_back({i - last - 1, last + 1});
            rest += mxs(i - last - 1);
            last = i;
        }
    }

    sort(lens.begin(), lens.end());

    vector<int> ans;
    for (int i = 0, len = lens.size(); i < len; i++) {
        auto& p = lens[i];
        rest -= mxs(p.first);
        if (p.first < b) {
            continue;
        }

        int cl = p.first;

        int x = p.first / b;
        for (int j = 1; j <= x; j++) {
            ans.push_back(p.second + j * b - 1);
            cl -= b;
            if (rest + mxs(cl) < a) {
                break;
            }
        }

        if (rest + mxs(cl) < a) {
            break;
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}