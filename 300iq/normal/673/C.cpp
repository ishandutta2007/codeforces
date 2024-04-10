#include <bits/stdc++.h>

#define fc first
#define sc second
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

ll cnt[5001];
ll ans[5001];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof cnt);
        int j = i;
        int cur_max = j;
        while (j < n) {
            cnt[t[j]]++;
            if (cnt[t[j]] > cnt[t[cur_max]] || (cnt[t[j]] == cnt[t[cur_max]] && t[cur_max] > t[j])) {
                cur_max = j;
            }  
            ans[t[cur_max]]++;
            j++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}