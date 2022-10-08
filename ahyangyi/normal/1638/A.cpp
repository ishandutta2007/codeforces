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

        vector<int> data(n);
        int ordered_prefix = -1;
        for (int i = 0; i < n; ++i)
        {
            cin >> data[i];
        }
        while (ordered_prefix + 1 < n && data[ordered_prefix + 1] == ordered_prefix + 2)
        {
            ++ordered_prefix;
        }
        int one_id = -1;
        for (int i = 0; i < n; ++i)
        {
            if (data[i] == ordered_prefix + 2)
            {
                one_id = i;
            }
        }

        for (int i = 0; i <= ordered_prefix; ++i)
        {
            cout << data[i] << " ";
        }
        if (one_id != -1)
        {
            for (int i = one_id; i > ordered_prefix; --i)
            {
                cout << data[i] << " ";
            }
            for (int i = one_id + 1; i < n; ++i)
            {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}