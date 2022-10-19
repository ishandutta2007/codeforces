#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, a, b, k;
int h[N];

int main()
{
    scanf("%d%d%d%d", &n, &a, &b, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &h[i]);
    }
    int ans = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        int q = h[i] / (a + b);
        if (h[i] % (a + b) > 0)
            ++q;
        --q;
        h[i] -= q * (a + b);
        h[i] -= a;
        if (h[i] <= 0)
        {
            ++ans;
            continue;
        }
        q = h[i] / a;
        if (h[i] % a > 0)
            ++q;
        v.push_back(q);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (k >= v[i])
        {
            ++ans;
            k -= v[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}