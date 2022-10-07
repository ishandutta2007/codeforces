#include <iostream>

using namespace std;
int a[200], b[200], res[200];

int main()
{
    int n, count, i, j, m, k, ans;
    cin >> n >> m >> k;
    for (i = 0; i < m; i++)
        cin >> a[i];
    for (i = 0; i < k; i++)
        cin >> b[i];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (b[j] % a[i] == 0)
                 res[i]++;
        }
    }
    ans = res[0];
    for (i = 0; i < m; i++)
        ans = min(res[i], ans);

    count = 0;
    for (i = 0; i < m; i++)
        if (res[i] == ans)
            count++;
    cout << count << "\n";
    for (i = 0; i < m; i++)
        if (ans == res[i])
            cout << i + 1 << " ";

    return 0;
}