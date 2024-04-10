#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 102;

int n, m;
int a[N];

int q[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        int ysum = sum - m;
        int ans = 0;
        for (int j = M - 2; j >= 1; --j)
        {
            if (ysum <= 0)
                break;
            if (ysum - (q[j] * j) > 0)
            {
                ysum -= (q[j] * j);
                ans += q[j];
            }
            else
            {
                if (ysum % j == 0)
                {
                    ans += (ysum / j);
                }
                else
                {
                    ans += (ysum / j + 1);
                }
                ysum = 0;
            }
        }
        q[a[i]]++;
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}