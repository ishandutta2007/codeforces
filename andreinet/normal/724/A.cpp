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

    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const string week[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = find(week, week + 7, s1) - week;
    int n2 = find(week, week + 7, s2) - week;

    for (int r = 0; r < 7; ++r) {
        int s = r;
        for (int i = 0; i < 12 - 1; ++i) {
            if (s % 7 == n1 && (s + days[i]) % 7 == n2) {
                cout << "YES\n";
                return 0;
            }
            s += days[i];
        }
    }

    cout << "NO\n";
    return 0;
}