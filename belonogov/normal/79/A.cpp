#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//vector <int> a;
int  a[10000];


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
*/  int x, y, i;
    cin >> x >> y;
    for (i = 0; i < 1000000; i++)
    {
        if (i % 2 == 0)
        {
            if (x >= 2 && y >= 2)
            {
                x -= 2;
                y -= 2;
            }
            else
            if (x >= 1 && y >= 12)
            {
                x -= 1;
                y -= 12;
            }else
            if (y >= 22)
            {
                x -= 0;
                y -= 22;
            }
            else
            {
                cout << "Hanako";
                return 0;
            }
        }
        if (i % 2 == 1)
        {
            if (y >= 22)
            {
                x -= 0;
                y -= 22;
            }
            else
            if (x >= 1 && y >= 12)
            {
                x -= 1;
                y -= 12;
            }else
            if (x >= 2 && y >= 2)
            {
                x -= 2;
                y -= 2;
            }
            else
            {
                cout << "Ciel";
                return 0;
            }
        }

    }
//Ciel.   ,  Hanako.

    return 0;
}