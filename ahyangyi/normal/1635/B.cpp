#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ct;
    cin >> ct;
    for (int t = 0; t < ct; ++t)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            if (i - 1 >= 0 && i + 1 < n && a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                if (i + 3 < n && a[i + 2] > a[i + 1] && a[i + 2] > a[i + 3])
                {
                    a[i + 1] = std::max(a[i], a[i + 2]);
                    ++ans;
                }
                else
                {
                    a[i] = std::max(a[i - 1], a[i + 1]);
                    ++ans;
                }
            }
        }
        cout << ans << endl;
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}