#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
int ind[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        ind[x] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[ind[x]] = i;
    }
    /*for (int i = 1; i <= n; ++i)
        cin >> a[i];*/
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (v.empty() || a[i] < v.back())
        {
            v.push_back(a[i]);
        }
        else
        {
            int l = 0, r = v.size() - 1;
            while ((r - l) > 4)
            {
                int m = (l + r) / 2;
                if (a[i] < v[m])
                    l = m;
                else
                    r = m;
            }
            bool z = false;
            for (int m = r; m >= l; --m)
            {
                if (a[i] < v[m])
                {
                    v[m + 1] = max(v[m + 1], a[i]);
                    z = true;
                }
            }
            if (!z)
                v[0] = max(v[0], a[i]);
        }
    }
    cout << v.size() << endl;
    return 0;
}