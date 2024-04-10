#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, S = 1000;
int a[MAXN], b[MAXN], p[MAXN], xx[MAXN];

int getNextX(int &x) {
    x = ((long long)x * 37 + 10007) % 1000000007;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, d, x;
    cin >> n >> d >> x;
    for(int i = 0; i < n; i++)
        a[i] = i;
    for(int i = 0; i < n; i++)
        swap(a[i], a[getNextX(x) % (i + 1)]);
    for(int i = 0; i < d; i++)
        b[i] = 1;
    for(int i = d; i < n; i++)
        b[i] = 0;
    for(int i = 0; i < n; i++)
        swap(b[i], b[getNextX(x) % (i + 1)]);
    for(int i = 0; i < n; i++)
        p[a[i]] = i;
    d = 0;
    for(int i = 0; i < n; i++)
        if(b[i])
            xx[d++] = i;
    for(int i = 0; i < n; i++) {
        int ans = -1;
        for(int j = n - 1; j >= n - S && j >= 0; j--)
            if(p[j] <= i && b[i - p[j]]) {
                ans = j;
                break;
            }
        if(ans >= 0) {
            cout << ans + 1 << '\n';
            continue;
        }
        for(int j = 0; j < d && xx[j] <= i; j++)
            if(a[i - xx[j]] > ans)
                ans = a[i - xx[j]];
        cout << ans + 1 << '\n';
    }
    return 0;
}