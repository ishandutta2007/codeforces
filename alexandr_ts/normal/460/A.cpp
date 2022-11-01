#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int cur = n;
    int ans = 0;
    while (cur > 0)
    {
        cur--;
        ans++;
        if (!(ans % m))
            cur++;
    }
    cout << ans << endl;
    return 0;
}