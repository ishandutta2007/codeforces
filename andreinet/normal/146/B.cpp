#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int getMask(int x) {
    int pw10 = 1e8;
    int ret = 0;
    for (; pw10 >= 1; pw10 /= 10) {
        int c = x / pw10 % 10;
        if (c == 4 || c == 7) ret = 10 * ret + c;
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    for (a++; getMask(a) != b; ++a);
    cout << a << '\n';
}