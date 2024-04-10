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

    int n;
    string s;
    cin >> n >> s;

    int len = 0;
    bool inside = false;
    int cnt = 0;
    int mxlen = 0;
    for (char c: s) {
        if (c == '(') {
            inside = true;
            mxlen = max(mxlen, len);
            len = 0;
        } else if (c == ')') {
            inside = false;
            cnt += len != 0;
            len = 0;
        } else if (c == '_') {
            if (inside) {
                cnt += len != 0;
            } else {
                mxlen = max(mxlen, len);
            }
            len = 0;
        } else {
            len++;
        }
    }
    mxlen = max(mxlen, len);

    cout << mxlen << ' ' << cnt << '\n';
}