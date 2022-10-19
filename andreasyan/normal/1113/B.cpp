#include <bits/stdc++.h>
using namespace std;
const int N = 50004;

int n;
int a[N];
multiset<int> s;

int ans, sum;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        s.insert(a[i]);
    }
    ans = sum;
    for (int i = 1; i <= n; ++i)
    {
        s.erase(s.find(a[i]));
        sum -= a[i];
        int x = *s.begin();
        for (int j = 1; j <= a[i]; ++j)
        {
            if (a[i] % j == 0)
            {
                sum += (a[i] / j);
                sum += (x * (j - 1));
                ans = min(ans, sum);
                sum -= (a[i] / j);
                sum -= (x * (j - 1));
            }
        }
        s.insert(a[i]);
        sum += a[i];
    }
    cout << ans << endl;
    return 0;
}