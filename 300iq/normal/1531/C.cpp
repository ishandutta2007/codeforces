#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }
    int k = 0;
    while ((k + 1) * (k + 1) <= n) k++;
    while ((n - k * k) % 2) k--;
    int rest = (n - k * k) / 2;
    int mx = (rest + k - 1) / k;
    int ans = k + mx;
    cout << ans << endl;
    vector <int> hist(k);
    vector <int> top;
    for (int i = 0; i < k; i++) {
        hist[i] = k + rest / k + (i < rest % k);
        top.push_back(rest / k + (i < rest % k));
    }
    sort(top.rbegin(), top.rend());
    for (int i = 0; i < rest / k; i++) {
        hist.push_back(k);
    }
    if (rest % k) hist.push_back(rest % k);
    vector <vector <char> > s(ans, vector <char> (ans, '.'));
    for (int i = 0; i < ans; i++) {
        for (int j = 0; j < hist[i]; j++) {
            s[ans - 1 - j][i] = 'o';
        }
    }
    for (int i = 0; i < ans; i++) {
        for (int j = 0; j < ans; j++) cout << s[i][j];
        cout << '\n';
    }
}