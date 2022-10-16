#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int lint;
const int NMAX = 100000 + 5;

int n;
int v[NMAX];

lint aibCnt[NMAX];
lint aibSum[NMAX];

inline int lsb(int node) {
    return node & (-node);
}

void update(lint aib[], int where, lint val) {
    for (; where <= n; where += lsb(where))
        aib[where] += val;
}

lint query(lint aib[], int where) {
    lint ans = 0;
    for (; where; where -= lsb(where))
        ans += aib[where];
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    cout << fixed << setprecision(16);

    long double ans = 0;
    lint sum = 0;
    for (int j = 1; j <= n; ++ j) {
        ans += sum * (n - j + 1LL);
        sum += j;
    }

    for (int i = n; i; -- i) {
        ans += query(aibCnt, v[i]) * (n * (n + 1LL) - 2 * i * (n + 1LL));
        ans += 2 * i * query(aibSum, v[i]);

        update(aibCnt, v[i], 1);
        update(aibSum, v[i], i);
    }

    ans = ans / (n + 1.0) / n;
    cout << ans << '\n';
    return 0;
}