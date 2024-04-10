#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n];

    for(int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }

    int maxs = 1;

    while(next_permutation(a, a + n))
    {
        int curs = 0;
        for(int i = 0; i < n; ++i)
        {
            int curmin = a[i];
            for(int j = i; j < n; ++j)
            {
                curmin = min(curmin, a[j]);
                curs += curmin;
            }
        }
        maxs = max(curs, maxs);
    }

    int num = 0;

    while(num < m)
    {
        int curs = 0;
        for(int i = 0; i < n; ++i)
        {
            int curmin = a[i];
            for(int j = i; j < n; ++j)
            {
                curmin = min(curmin, a[j]);
                curs += curmin;
            }
        }
        if(curs == maxs)
            ++num;
        if(num == m)
            break;
        next_permutation(a, a + n);
    }

    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}