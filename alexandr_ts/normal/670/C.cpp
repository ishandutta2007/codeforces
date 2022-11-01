#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;

map <int, int> m;

pair <int, int> a[N];

bool cmp(pair <int, int> &a, pair <int, int> &b) {
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    if (m.count(a.first))
        a1 = m[a.first];
    if (m.count(b.first))
        b1 = m[b.first];
    if (a1 != b1)
        return a1 < b1;
    else {
        if (m.count(a.second))
            a2 = m[a.second];
        if (m.count(b.second))
            b2 = m[b.second];
        return a2 < b2;
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        int x;
        cin >> x;
        m[x]++;
    }
    int k;
    cin >> k;
    fr(i, k)
        cin >> a[i].first;
    fr(i, k)
        cin >> a[i].second;
    int ans = 0;
    frab(i, 1, k)
        if (cmp(a[ans], a[i]))
            ans = i;
    cout << ans + 1;
}