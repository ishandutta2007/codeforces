#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    long long ans = 0;
    int max_b = 0, second_max_b = 0;
    for (int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;

        ans += b * (long long)m;

        if (b > max_b)
        {
            second_max_b = max_b;
            max_b = b;
        }
        else if (b > second_max_b)
        {
            second_max_b = b;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int g;
        cin >> g;
        if (g < max_b)
        {
            cout << "-1" << endl;
            return 0;
        }
        else if (g == max_b)
        {
            second_max_b = max_b;
        }

        ans += (g - max_b);
    }
    cout << ans + (max_b - second_max_b) << endl;

    return 0;
}