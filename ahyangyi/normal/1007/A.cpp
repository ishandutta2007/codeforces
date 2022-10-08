#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;

    cin >> n;

    map<int,int> m;
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        ans = std::max(ans, ++m[t]);
    }

    cout << n - ans << endl;

    return 0;
}