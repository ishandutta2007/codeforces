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
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> let = {'R', 'B', 'Y', 'G'};
    int pos[4];
    for (int i = 0; i < 4; ++i) {
        char c = let[i];
        pos[(find(s.begin(), s.end(), c) - s.begin()) & 3] = i;
    }
    int cnt[4] = {0};
    for (int i = 0; i < SZ(s); ++i) {
        if (s[i] == '!') {
            cnt[pos[i & 3]]++;
        }
    }
    for (int i = 0; i < 4; ++i) {
        cout << cnt[i] << ' ';
    }
    cout << '\n';
}