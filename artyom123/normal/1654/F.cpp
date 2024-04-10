#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define mp make_pair
#define ld long double
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> cl(n + 1, vector<int>(1 << n));
    for (int i = 0; i < (1 << n); i++) cl[0][i] = s[i] - 'a';
    for (int j = 1; j <= n; j++) {
        vector<pii> a(1 << n);
        for (int i = 0; i < (1 << n); i++) {
            a[i] = mp(cl[j - 1][i], cl[j - 1][i ^ (1 << (j - 1))]);
        }
        vector<pii> b = a;
        sort(all(b));
        for (int i = 0; i < (1 << n); i++) cl[j][i] = lower_bound(all(b), a[i]) - b.begin();
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (cl[n][i] < cl[n][ans]) ans = i;
    }
    for (int i = 0; i < (1 << n); i++) cout << s[i ^ ans];
    return 0;
}