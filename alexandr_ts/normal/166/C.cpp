#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e6;
const ld EPS = 1e-8;
const ld INF = 1e9;

int a[N];

int main() {
    ld st = clock();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    int l = 0, e = 0, b = 0;
    fr(i, n)
        if (a[i] == m) e++;
        else if (a[i] < m) l++;
        else b++;
    int ans = INF;
    fr(l1, n + 2)
        fr(e1, n + 2)
            fr(b1, n + 2)
                if ((l + l1) < e + b + e1 + b1 && l + l1 + e + e1 >= b + b1)
                    ans = min(ans, l1 + e1 + b1);
    cout << ans;

}