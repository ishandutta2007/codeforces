#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> b(n);
        for (auto &c : b) cin >> c;
        int left = -1, right = 2e5 + 10;
        vector<int> cntaa(101), cntbb(101);
        for (auto &c : a) cntaa[c]++;
        for (auto &c : b) cntbb[c]++;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            int k = n + mid;
            vector<int> cnta = cntaa;
            vector<int> cntb = cntbb;
            cnta[100] += mid;
            cntb[0] += mid;
            int need = k - k / 4;
            int ta = 0, tb = 0;
            ll suma = 0, sumb = 0;
            for (int i = 100; i >= 0; i--) {
                int tmpa = min(cnta[i], need - ta);
                suma += i * tmpa;
                ta += tmpa;
                int tmpb = min(cntb[i], need - tb);
                sumb += i * tmpb;
                tb += tmpb;
            }
            if (suma >= sumb) right = mid;
            else left = mid;
        }
        cout << right << "\n";
    }
    return 0;
}