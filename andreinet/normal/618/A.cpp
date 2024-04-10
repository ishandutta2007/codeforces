#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> s;
    while (n-- > 0) {
        int v = 1;
        while (!s.empty() && v == s.back()) {
            s.pop_back();
            ++v;
        }
        s.push_back(v);
    }
    for (int p: s) cout << p << ' ';
    cout << '\n';
}