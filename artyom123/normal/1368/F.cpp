#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n <= 3) {
        cout << 0 << endl;
        return 0;
    }
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (n - k - (n + k - 1) / k < n - i - (n + i - 1) / i) k = i;
    }
    //cout << "k = " << k << endl;
    vector<int> usd(n);
    for (int i = 0; i < n; i++) {
        //cout << '?' << " " << i << endl;
        for (int j = i; j < n - 1 && j < i + k - 1; j++) {
            usd[j] = 1;
            //cout << '!' << j << endl;
        }
        i += k - 1;
    }
    vector<int> col(n);
    while (1) {
        vector<int> cnt;
        for (int i = 0; i < n; i++) {
            if (col[i] == 0 && usd[i]) cnt.pb(i);
        }
        if ((int)cnt.size() < k) {
            cout << 0 << endl;
            return 0;
        }
        cout << k << " ";
        for (int i = 0; i < k; i++) {
            cout << cnt[i] + 1 << " ";
            col[cnt[i]] = 1;
        }
        cout << endl;
        int x;
        cin >> x;
        x--;
        for (int i = x; i < x + k; i++) {
            col[i % n] = 0;
        }
    }
    return 0;
}