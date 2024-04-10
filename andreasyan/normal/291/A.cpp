#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
int a[N];

map<int, int> mp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
            continue;
        mp[a[i]]++;
        if (mp[a[i]] > 2)
        {
            cout << "-1" << endl;
            return 0;
        }
        else if (mp[a[i]] == 2)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}