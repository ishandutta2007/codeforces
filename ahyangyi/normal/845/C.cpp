#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());

    int t0 = -1, t1 = -1;
    bool ok = true;
    for (const auto p : v)
    {
        if (p.first > t0)
        {
            t0 = p.second;
        }
        else if (p.first > t1)
        {
            t1 = p.second;
        }
        else
        {
            ok = false;
        }
    }
    if (ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}