#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int a[MAXN], cnt[MAXN], f[MAXN], pos[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int nn = 1;
    cnt[0] = 1;
    for(int i = 1; i < n; i++)
        if(a[i] == a[nn - 1])
            cnt[nn - 1]++;
        else {
            a[nn] = a[i];
            cnt[nn] = 1;
            nn++;
        }
    n = nn;
    int ans = 2;
    for(int i = 0; i < n; i++)
        if(a[i] == 0)
            ans = max(ans, cnt[i]);
    for(int i = 0; i < n; i++) {
        cnt[i]--;
        for(int j = 0; j < n; j++) {
            if(!cnt[j])
                continue;
            cnt[j]--;
            f[0] = a[i];
            f[1] = a[j];
            int len = 2;
            while(true) {
                f[len] = f[len - 1] + f[len - 2];
                pos[len] = lower_bound(a, a + n, f[len]) - a;
                if(pos[len] == n || a[pos[len]] != f[len] || !cnt[pos[len]])
                    break;
                cnt[pos[len]]--;
                len++;
            }
            ans = max(ans, len);
            for(int k = 2; k < len; k++)
                cnt[pos[k]]++;
            cnt[j]++;
        }
        cnt[i]++;
    }
    cout << ans << '\n';
    return 0;
}