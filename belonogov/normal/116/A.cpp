#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int i, n, ans = 0, res = 0, x, y;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        res +=  y - x;
        ans = max(ans, res);
    }
    cout << ans;

    return 0;
}