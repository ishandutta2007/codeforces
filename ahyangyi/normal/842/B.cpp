#include <iostream>

using namespace std;

int main()
{
    int r, d, n;
    cin >> r >> d >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y, R;
        cin >> x >> y >> R;
        if (x*x + y*y >= (r-d+R)*(r-d+R) && x*x + y*y <= (r-R)*(r-R))
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}