#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    int n, start, x;
    cin >> n >> start >> x;
    vi v;
    v.pb(start);
    for (int i = 1; i <= 750; i++) {
        int p = Rand(1, n);
        v.pb(p);
    }
    vector<ii> vv;
    for (auto u : v) {
        cout << "? " << u << endl;
        int val, nx;
        cin >> val >> nx;
        vv.pb({val, u});
    }
    sort(all(vv));
    int pivot = start;
    for (auto u : vv) {
        if (u.x >= x) break;
        pivot = u.y;
    }
    int ans = -1;
    while (1) {
        cout << "? " << pivot << endl;
        int val, nx;
        cin >> val >> nx;
        if (val >= x) {
            ans = val;
            break;
        }
        if (nx == -1) break;
        pivot = nx;
    }
    cout << "! " << ans << endl;
    return 0;
}