#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 30;
const int N = 1e6 + 10;

int v[N], t[N];
ll pref[N];

ll add[N];
ll cnt[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i + 1]);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i + 1]);
    for (int i = 1; i <= n + 5; i++)
        pref[i] = pref[i - 1] + t[i];
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(pref + i, pref + n + 2, v[i] + pref[i - 1]) - pref;
        //cout << i << " " << j << endl;
        cnt[j] -= 1;
        cnt[i] += 1;
        add[j] += v[i] - (pref[j - 1] - pref[i - 1]);
    }
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 1; i <= n; i++)
        cnt[i] *= t[i];
    for (int i = 1; i <= n; i++)
        cout << cnt[i] + add[i] << " ";
}