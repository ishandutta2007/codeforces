#include <iostream>
#include <map>

using namespace std;

int main()
{
    map < int, int > m;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
        if (a)
        {
            if (m[a] == 2)
            {
                ans++;
            }
            if (m[a] == 3)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}