#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    int n;
    cin >> n;
    vector<int> ans(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt.assign(n, 0);
        ++cnt[a[i]];
        int k = 1, color = a[i];
        ++ans[color];
        for (int j = i + 1; j < n; ++j) {
            ++cnt[a[j]];
            if (cnt[a[j]] > k || (cnt[a[j]] == k && a[j] < color)) {
                k = cnt[a[j]];
                color = a[j];
            }
            ++ans[color];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}