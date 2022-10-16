#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2005, MAXX = 5005;
int a[MAXN];
long double p[MAXX], p2[MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            p[a[j] - a[i]] += 2.l / (n * (n - 1));
    for(int i = 0; i < MAXX; i++)
        for(int j = 0; i + j < MAXX; j++)
            p2[i + j] += p[i] * p[j];
    long double sum = 0, ans = 0;
    for(int i = MAXX - 1; i >= 0; i--) {
        ans += p2[i] * sum;
        sum += p[i];
    }
    cout << ans << '\n';
    return 0;
}