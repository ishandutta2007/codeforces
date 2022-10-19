#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, k;
int a[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> v;
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        v.push_back(a[i] - a[i - 1]);
        ans += (a[i] - a[i - 1]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < k - 1; ++i)
        ans -= v[i];
    cout << ans << endl;
    return 0;
}