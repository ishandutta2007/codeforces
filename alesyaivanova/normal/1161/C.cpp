#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define pii pair<long long, long long>

const int MAXN = 100;
int a[MAXN];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - n / 2; i++)
    {
        if (a[i] != a[i + 1])
        {
            cout << "Alice";
            return 0;
        }
    }
    cout << "Bob";
}