#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        map<int, vector<int> > l;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int pw = 0;
            while (a[i] % x == 0) {
                a[i] /= x;
                pw++;
            }
            l[a[i]].push_back(pw);
        }
        auto solve = [&](vector<int> a) {
            map <int, int> cnt;
            int n = (int) a.size();
            for (int x : a) cnt[x]++;
            int ans = 0;
            sort(a.begin(), a.end());
            map <int, int> mp;
            for (int i = 0; i < n; i++) {
                if (mp[a[i]] < cnt[a[i]]) {
                    if (mp[a[i] + 1] < cnt[a[i] + 1]) mp[a[i] + 1]++;
                    else ans++;
                    mp[a[i]]++;
                }
            }
            return ans;
        };
        int sum = 0;
        for (auto c : l) sum += solve(c.second);
        cout << sum << endl;
    }
}