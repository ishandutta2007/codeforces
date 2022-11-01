#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second, a[i].second--;
    sort(all(a), greater<pair<int, int>>());
    vector<int> cnt(200, 0);
    for(int i = 0; i < n; i++) cnt[a[i].second]++;
    int ans = 2e7, cur = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j != n - 1 && a[j + 1].first == a[i].first) j++;
        for(int k = i; k <= j; k++) cnt[a[k].second]--;

        int u = max(0, (n - j - 1) - (j - i + 1) + 1);
        int add = 0;
        for(int c = 0; c < 200; c++)
            if(cnt[c] <= u) add += (c + 1) * cnt[c], u -= cnt[c];
            else {
                add += u * (c + 1);
                break;
            }

        ans = min(ans, add + cur);

        for(int k = i; k <= j; k++) cur += a[k].second + 1;
        i = j;
    }
    cout << ans;
}