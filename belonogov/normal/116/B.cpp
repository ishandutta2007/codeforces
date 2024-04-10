#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
//vector <int> a;
string  a[100];

int main()
{
   /* int n, i, x;
    cin >> n;
   for (i = 0; i < n; i++)
    {
        cin >> x;
        a.insert(x);
    }
    set<int>::iterator j;
    for (j = a.begin(); j != a.end(); j++)
    {
        cout << *j << " ";
    }
    cout << "\n";
    cout << *a.upper_bound(20);

    for (i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (i = 0; i < n; i++)
        cout << a[i];
*/
    int n, i, m, j, count;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    count = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if(a[i][j] == 'P')
            {
                if(j - 1 >= 0 && a[i][j - 1] == 'W')
                {
                    a[i][j] = '.';
                    a[i][j - 1] = '.';
                    count++;
                }else
                if(j + 1 < m && a[i][j + 1] == 'W')
                {
                    a[i][j] = '.';
                    a[i][j + 1] = '.';
                    count++;
                }else
                if(i - 1 >= 0 && a[i - 1][j] == 'W')
                {
                    a[i][j] = '.';
                    a[i - 1][j] = '.';
                    count++;
                }else
                if(i + 1 < n && a[i + 1][j] == 'W')
                {
                    a[i][j] = '.';
                    a[i + 1][j] = '.';
                    count++;
                }
            }

    cout << count;
    return 0;
}