#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], r[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    r[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--)
        r[i] = a[i] < a[i + 1]? r[i + 1] : i;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = r[i];
        ans = max(ans, j - i + 1);
        if(j + 1 == n)
            continue;
        if(a[j + 1] > (j == i? -1 : a[j - 1]) + 1)
            ans = max(ans, r[j + 1] - i + 1);
        j++;
        ans = max(ans, j - i + 1);
        if(j + 1 == n)
            continue;
        if(a[j + 1] > a[j - 1] + 1)
            ans = max(ans, r[j + 1] - i + 1);
    }
    cout << ans << '\n';
    return 0;
}