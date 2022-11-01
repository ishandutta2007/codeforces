#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int M = 1e7 + 1;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int a[N], b[N];
bool used[N];

void dfs(int v) {
    used[v] = true;
    if (!used[a[v]])
        dfs(a[v]);
}

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    fr(i, n) {
        cin >> a[i];
        a[i]--;
    }
    fr(i, n)
        cin >> b[i];
    int cnt = 0;
    fr(i, n)
        if (!used[i])
            dfs(i), cnt++;
    int s = 0;
    fr(i, n)
        s += b[i];
    s %= 2;
    if (cnt == 1 && s == 1) {
        cout << 0;
        return 0;
    }
    else if (cnt == 1 && s == 0) {
        cout << 1;
        return 0;
    }
    cout << cnt + !s;

}