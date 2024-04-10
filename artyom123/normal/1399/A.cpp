#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

const int MAXN = 1e6 + 5;

int main(){
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
        sort(all(a));
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 1) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}