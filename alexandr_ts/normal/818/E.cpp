#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 2;

ll a[N];

map <int, int> m[N];

map <int, int> f(int x) {
    map <int, int> ans;
    while (x > 1) {
        bool fnd = false;
        for (int i = 2; i * i <= x && !fnd; i++)
            if (x % i == 0) {
                fnd = true;
                ans[i]++;
                x /= i;
            }
        if (!fnd) {
            ans[x]++;
            x = 1;
        }
    }
    return ans;
}

void merg(map <int, int> &a, map <int, int> &b) {
    for (auto t: b)
        a[t.first] += t.second;
}

bool maj(map <int, int> &a, map <int, int> &b) {
    for (auto t: b)
        if (!a.count(t.first) || a[t.first] < t.second)
            return false;
    return true;
}

void del(map <int, int> &a, map <int, int> &b) {
    for (auto t: b) {
        a[t.first] -= t.second;
        if (!a[t.first])
            a.erase(t.first);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;

    map <int, int> nums;

    fr(i, n) {
        cin >> a[i];
        a[i] = __gcd(a[i], k);
        if (nums.count(a[i]))
            m[i] = m[nums[a[i]]];
        else {
            nums[a[i]] = i;
            m[i] = f(a[i]);
        }
    }

    map <int, int> cur = m[0];
    map <int, int> ks = f(k);

    ll ans = 0;
    int y = n - 1;
    fr(x, n) {
        while (y >= 0 && !maj(cur, ks) || x + y >= n) {
            merg(cur, m[n - y]);
            y--;
        }
        //cout << x << " " << y << endl;
        if (maj(cur, ks))
            ans += (ll)(y + 1);
        del(cur, m[x]);
    }
    cout << ans;
}