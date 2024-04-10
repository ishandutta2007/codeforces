#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, k;

vector<int> ans;

int main()
{
    cin >> n >> k;
    if (n <= k)
    {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    if (n <= k + 1 + k)
    {
        cout << 1 << endl << k + 1 << endl;
        return 0;
    }
    int ss;
    for (int s = k + 1; s >= 1; --s)
    {
        if ((n - (s + k)) % (2 * k + 1) >= (k + 1))
        {
            ss = s;
            break;
        }
    }
    for (int i = ss; i <= n; i += (2 * k + 1))
    {
        ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}