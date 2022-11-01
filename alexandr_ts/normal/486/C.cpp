#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6e6 + 10;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 6e6 + 1;

ll dist[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    m--;
    if (m >= n / 2)
        m = n - 1 - m;
    cin >> s;
    fr(i, s.size())
        dist[i] = min(26 - abs(s[i] - s[n - 1 - i]), abs(s[i] - s[n - 1 - i]));
    //fr(i, s.size())
       // cout << dist[i] << " ";cout << endl;
    int l = 0, r = (n - 1) / 2;
    while (!dist[l] && (l) < n / 2) l++;
    while (!dist[r] && r > 0) r--;
    //cout << l << " " << r << endl;
    int t1 = m - l;
    int t2 = r - m;
    int t;
    if (r < l) {
    cout << 0; return 0;}
    if (m - l < 0) t = t2, l = r = 0;
    else if (r - m < 0) t = t1, l = r = 0;
    else t = min(t1, t2);
    cout << accumulate(dist, dist + n / 2, 0) + (r - l) + t;
}