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
    cin.tie(0);

    int f;
    cin >> f;

    int n1, n2;
    cin >> n1;
    cin.get();
    cin >> n2;

    if (f == 12) {
        if (n1 > 12 || n1 == 0) {
            if (n1 % 10 == 0) {
                n1 = 10;
            } else {
                n1 %= 10;
            }
        }
    } else {
        if (n1 >= 24) {
            n1 %= 10;
        }
    }
    if (n2 > 59) {
        n2 %= 10;
    }
    printf("%02d:%02d", n1, n2);
}