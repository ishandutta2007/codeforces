#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int MAXN = 200009;
int a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if ((n * (2 * n + 1)) % 2 == 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = 2 * i + 1;
        a[i + n] = 2 * i + 2;
        if (i % 2)
            swap(a[i], a[i + n]);
    }
    for (int i = 0; i < 2 * n; i++)
        cout << a[i] << " ";
}