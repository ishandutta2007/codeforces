#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &e : a) cin >> e;
        for (int &e : b) cin >> e;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> prefa, prefb;
        prefa = a;
        prefb = b;
        for (int i = 1; i < n; i++) prefa[i] += prefa[i - 1], prefb[i] += prefb[i - 1];
        int res = 0;
        int l = 0, r = 1000000;
        while (r >= l) {
            int mid = (l + r) / 2;
            int eli = (mid + n) / 4;
            int score_a = prefa.back() + 100 * mid;
            if (eli <= n) score_a -= (eli == 0 ? 0 : prefa[eli - 1]);
            else score_a -= prefa[n - 1] + 100 * (eli - n);
            int score_b = prefb.back();
            if (eli > mid) score_b -= prefb[eli - mid - 1]; 
            if (score_a >= score_b) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << res << '\n';
    }

    return 0;
}