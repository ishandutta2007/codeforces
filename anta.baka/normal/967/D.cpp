#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int mod = 1e9 + 7;

void print(vector<pair<int, int>> &a, int p, int q, bool re) {
    vector<int> v1, v2;
    for(int i = 0; i <= p; i++) v1.push_back(a[i].second);
    for(int i = p + 1; i <= q; i++) v2.push_back(a[i].second);
    if(re) swap(v1, v2);
    cout << "Yes\n";
    cout << sz(v1) << ' ' << sz(v2) << '\n';
    for(int x : v1) cout << x + 1 << ' ';
    cout << '\n';
    for(int x : v2) cout << x + 1 << ' ';
    exit(0);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, x1, x2; cin >> n >> x1 >> x2;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(all(a), greater<pair<int, int>>());

    int j = -1;
    for(int i = 0; i < n; i++)
        if(a[i].first * ll(i + 1) >= x1) {
            j = i; break;
        }
    if(j != -1) {
        for(int i = j + 1; i < n; i++)
            if(a[i].first * ll(i - j) >= x2) {
                print(a, j, i, false);
            }
    }

    j = -1;
    for(int i = 0; i < n; i++)
        if(a[i].first * ll(i + 1) >= x2) {
            j = i; break;
        }
    if(j != -1) {
        for(int i = j + 1; i < n; i++)
            if(a[i].first * ll(i - j) >= x1) {
                print(a, j, i, true);
            }
    }

    cout << "No";
}