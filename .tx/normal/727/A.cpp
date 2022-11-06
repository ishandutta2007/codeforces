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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(a, b);

    unordered_map<int, int> d;
    d[a] = -1;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == b) {
            break;
        }
        lint q1 = 1LL * v * 2;
        lint q2 = 10LL * v + 1;
        if (q1 <= b && d.find(q1) == d.end()) {
            q.push(q1);
            d[q1] = v;
        }

        if (q2 <= b && d.find(q2) == d.end()) {
            q.push(q2);
            d[q2] = v;
        }
    }

    if (d.find(b) == d.end()) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vector<int> ans;
    int x = b;
    while (x != -1) {
        ans.push_back(x);
        x = d[x];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}