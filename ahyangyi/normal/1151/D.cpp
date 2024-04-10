#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    long long ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        ans += (n - 1) * (long long)std::min(x, y);
        a[i] = x - y;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            ans += -a[i] * (long long)i;
        }
        else
        {
            ans += a[i] * (long long)(n - i - 1);
        }
    }
    cout << ans << endl;

    return 0;
}