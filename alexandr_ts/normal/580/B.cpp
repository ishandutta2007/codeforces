#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct guest {
    ll m, s;
};

bool cmp(guest a, guest b) {
    return a.m < b.m;
}

guest a[200100];
ll s[200100];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll n, d;
    cin >> n >> d;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].m >> a[i].s;
    s[0] = 0;
    sort(a + 1, a + n + 1, cmp);

    for (ll i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i].s;
    ll m = 0;
    ll j = 1;
    for (ll i = 1; i <= n; i++) {
        while (j <= n && a[i].m + d - 1 >= a[j].m)
            j++;
        if (j - i > 0) m = max(m, s[j - 1] - s[i - 1]);
        else m = max(m, s[i] - s[i - 1]);
        if (j == n + 1) break;

    }
    cout << m;
    return 0;
}