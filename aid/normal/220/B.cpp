#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5, K = 455;
int a[MAXN], cnt[MAXN], x[K], s[K][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < MAXN)
            cnt[a[i]]++;
    }
    int k = 0;
    for(int i = 1; i < MAXN; i++)
        if(cnt[i] >= i)
            x[k++] = i;
    for(int i = 0; i < k; i++) {
        s[i][0] = 0;
        for(int j = 0; j < n; j++)
            s[i][j + 1] = s[i][j] + (a[j] == x[i]);
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = 0;
        for(int j = 0; j < k; j++)
            ans += (s[j][r] - s[j][l] == x[j]);
        cout << ans << '\n';
    }
    return 0;
}