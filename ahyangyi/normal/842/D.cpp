#include <iostream>
#include <vector>

using namespace std;

int main()
{
    typedef int Bool;
    const int MaxB = 19;
    const int MaxN = 1 << MaxB;
    int n, m;
    vector<Bool> v(MaxN);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int a;

        cin >> a;
        v[a] = true;
    }

    vector<vector<Bool>> v_summary;
    v_summary.push_back(v);
    for (int i = 1; i < MaxB; ++i)
    {
        vector<Bool> v2(MaxN >> i);
        for (int j = 0; j < (MaxN >> i); ++j)
        {
            v2[j] = v_summary[i - 1][j << 1] && v_summary[i - 1][(j << 1) + 1];
        }
        v_summary.push_back(v2);
    }

    int x = 0;
    for (int i = 0; i < m; ++i)
    {
        int new_x;

        cin >> new_x;
        x ^= new_x;

        int ans = 0;
        for (int i = MaxB - 1; i >= 0; --i)
        {
            if (v_summary[i][(x ^ ans) >> i])
            {
                ans |= 1 << i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}