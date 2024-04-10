#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int q[n];
    q[0] = 2 - a[0];
    for (int i = 1; i < n; i++)
        q[i] = q[i - 1] + 2 - a[i];
    int t[n];
    t[n - 1] = a[n - 1] - 1;
    for (int i = n - 2; i >= 0; i--)
        t[i] = t[i + 1] + a[i] - 1;
    int ans = 1;
    for (int left = 0; left < n; left++)
    {
        int num2 = 0;
        int ma = 0;
        for (int right = left; right < n; right++)
        {
            if (a[right] == 1)
                ma++;
            else
            {
                num2++;
                if (num2 > ma)
                    ma = num2;
            }
            if (left == 0 && right == n - 1 && ma > ans)
                ans = ma;
            else if (left == 0 && right < n - 1 && ma + t[right + 1] > ans)
                ans = ma + t[right + 1];
            else if (left > 0 && right == n - 1 && q[left - 1] + ma > ans)
                ans = q[left - 1] + ma;
            else if (left > 0 && right < n - 1 && q[left - 1] + ma + t[right + 1] > ans)
                ans = q[left - 1] + ma + t[right + 1];
        }
    }
    cout << ans;
}