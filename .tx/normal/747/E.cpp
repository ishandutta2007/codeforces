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

vector<vector<string> > a;

void dfs(int d, int mx) {
    if (a.size() == d) {
        a.push_back(vector<string>());
    }
    int rd = 0;
    while (rd != mx) {
        rd++;
        string msg;
        char c;
        while (true) {
            if (!(cin >> c)) {
                return;;
            }
            if (c == ',') {
                break;
            }
            msg += c;
        }
        int num = 0;
        while (true) {
            if (!(cin >> c)) {
                break;
            }
            if (c == ',') {
                break;
            }
            num = num * 10 + c - '0';
        }
        a[d].push_back(msg);
        dfs(d + 1, num);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    dfs(0, -1);
    while (!a.empty() && a.back().empty()) {
        a.pop_back();
    }
    cout << a.size() << "\n";
    for (auto& i : a) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}