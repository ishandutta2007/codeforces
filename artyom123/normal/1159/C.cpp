#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

int INF = 1e9 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long n, m;
    cin >> n >> m;
    vector <long long> b(n);
    vector <long long> g(m);
    long long mig = INF;
    long long mab = -INF;
    for (auto &c : b) {
        cin >> c;
        mab = max(mab, c);
    }
    for (auto &c : g) {
        cin >> c;
        mig = min(mig, c);
    }
    if (mab > mig) {
        cout << -1;
        return 0;
    }
    multiset <long long> boys;
    for (auto &c : b) {
        boys.insert(c);
    }
    long long maxboy = *boys.rbegin();
    boys.erase(boys.find(*boys.rbegin()));
    long long ans = 0;
    for (auto &c : g) {
        ans += c;
    }
    if (mig == maxboy) {
        for (auto &c : boys) {
            ans += c * m;
        }
        cout << ans;
        return 0;
    }
    ans -= mig;
    ans += maxboy;
    int ind = 0;
    for (auto &c : boys) {
        if (ind == n - 2) {
            ans += mig;
            ans += (m - 1) * c;
        }
        else {
            ans += m * c;
        }
        ind++;
    }
    cout << ans;
    return 0;
}