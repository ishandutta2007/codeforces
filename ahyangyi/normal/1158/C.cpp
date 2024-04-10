#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int t;
    for (cin >> t; t --> 0;)
    {
        int n;
        cin >> n;

        bool fail=false;
        int lb = 1;
        vector<pair<int, int>> lr_pairs;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            while (lr_pairs.size() > 0 && lr_pairs.rbegin()->second == i)
            {
                ans[lr_pairs.rbegin()->first] = lb++;
                lr_pairs.pop_back();
            }

            int next;
            cin >> next;

            if (next != -1)
            {
                --next;
                if (lr_pairs.size() > 0 && next > lr_pairs.rbegin()->second)
                {
                    fail = true;
                }

                lr_pairs.push_back(make_pair(i, next));
            }
            else
            {
                ans[i] = lb++;
            }
        }
        while (lr_pairs.size() > 0)
        {
            ans[lr_pairs.rbegin()->first] = lb++;
            lr_pairs.pop_back();
        }

        if (fail)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}