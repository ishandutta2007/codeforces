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
*/
    int n, m, k, t, i, j, x, y, d;
    cin >> n >> m >> k >> t;
    for (i = 0; i < k; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        a[i] = x * m + y;
    }
    sort(a, a + k);
    for (i = 0; i < t; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        d = x * m + y;
        j = 0;
        while (a[j] < d && j < k)
            j++;
        if (a[j] == d)
            cout << "Waste\n";
        else
        {
            if ((d - j) % 3 == 0)
                cout << "Carrots\n";
            if ((d - j) % 3 == 1)
                cout << "Kiwis\n";
            if ((d - j) % 3 == 2)
                cout << "Grapes\n";

        }
        //Carrots, Kiwis  Grapes     ,    .
    }

    return 0;
}