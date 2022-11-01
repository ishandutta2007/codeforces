#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e2 + 10;
const int INF = 2e9;
const int ALPH = 300;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < min(n, m) && a[i] < 0; i++)
        ans += a[i];
    cout << -ans;

}