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

    string S;
    getline(cin, S);

    int x = 0, p = 0;
    while ('0' <= S[p] && S[p] <= '9')
        x = 10 * x + (S[p++] - '0');

    vector<int> months = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (S[SZ(S) - 1] == 'k') {
        int cnt = 366 / 7;
        int r = 366 % 7;
        x = (x - 5 + 7) % 7;
        if (x < r) ++cnt;
        cout << cnt << '\n';
    } else {
        int cnt = 0;
        for (int p: months) {
            cnt += x <= p;
        }
        cout << cnt << '\n';
    }
}