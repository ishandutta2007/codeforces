#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;
const int MAX = 1010;

int a[N], d[2 * MAX + 10];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    fill(d, d + 2 * MAX + 10, INF);

    //queue <int> q;

    fr(i, k)
        cin >> a[i];
    sort(a, a + k);
    k = unique(a, a + k) - a;

    queue <int> q;
    fr(i, k)
        a[i] = a[i] - n;
    fr(i, k) {
        d[a[i] + MAX] = 1;
        q.push(a[i] + MAX);
    }


    while (!q.empty()) {
        int v = q.front();
        q.pop();
        fr(i, k)
            if (v + a[i] >= 0 && v + a[i] <= 2 * MAX + 2)
                if (d[v + a[i]] > d[v] + 1) {
                    d[v + a[i]] = d[v] + 1;
                    q.push(v + a[i]);
                }
    }

    if (d[MAX] == INF)
        cout << -1;
    else
        cout << d[MAX];


}