#include <iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    long long ans = 0;
    int prev = -1;
    for (int i = 0; i < n; ++i)
    {
        int x;

        cin >> x;
        if (prev == -1)
        {
            ans += (long long)(n - x + 1) * x;
        }
        else if (prev < x)
        {
            ans += (long long)(x - prev) * (n - x + 1);
        }
        else
        {
            ans += (long long)(prev - x) * x;
        }

        prev = x;
    }
    cout << ans << endl;

    return 0;
}