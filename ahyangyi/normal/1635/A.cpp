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

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            ans |= a;
        }

        cout << ans << endl;
    }
    return 0;
}