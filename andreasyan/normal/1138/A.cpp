#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> v;
    int q = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            ++q;
        else
        {
            v.push_back(q);
            q = 1;
        }
    }
    v.push_back(q);
    int ans = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        ans = max(ans, min(v[i], v[i - 1]) * 2);
    }
    cout << ans << endl;
    return 0;
}