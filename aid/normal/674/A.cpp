#include <iostream>

using namespace std;

const int MAXN = 5005;
int a[MAXN], cnt[MAXN], ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int l = 0; l < n; l++) {
        for(int i = 0; i < n; i++)
            cnt[i] = 0;
        int best = a[l];
        cnt[a[l]]++;
        ans[best]++;
        for(int r = l + 1; r < n; r++) {
            cnt[a[r]]++;
            if(cnt[a[r]] > cnt[best] || (cnt[a[r]] == cnt[best] && a[r] < best))
                best = a[r];
            ans[best]++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}