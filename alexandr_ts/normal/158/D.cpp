#include <iostream>

using namespace std;

int a[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = -1000000000000;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && n / i >= 3)
        {
            for (int st = 0; st < i; st++)
            {
                long long s = 0;
                for (int j = st; j < n; j += i)
                    s += a[j];
                ans = max(ans, s);
            }
        }
    }
    cout << ans;
    return 0;
}