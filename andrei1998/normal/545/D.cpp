#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

int v[100005];

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    lint sum = 0;
    int ans = n;

    for (int i = 1; i <= n; i++)
        if (sum > v[i])
            ans --;
        else
            sum += v[i];

    cout << ans << '\n';
    return 0;
}