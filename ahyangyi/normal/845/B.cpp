#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m = 6;

    cin >> n;
    for (int i = 0; i < 1000000; ++i)
    {
        int diff = 0;
        int change = 0;
        int i2 = i;
        int n2 = n;
        for (int j = 0; j < 6; ++j)
        {
            int cur_i = i2 % 10;
            int cur_n = n2 % 10;
            i2 /= 10;
            n2 /= 10;
            if (cur_i != cur_n)
            {
                ++change;
            }
            if (j < 3)
            {
                diff += cur_i;
            }
            else
            {
                diff -= cur_i;
            }
        }

        if (diff == 0 && change < m)
        {
            m = change;
        }
    }
    cout << m << endl;

    return 0;
}