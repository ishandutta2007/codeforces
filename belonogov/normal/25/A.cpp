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
    int i, n, uk1 = 0, uk2 = 0, r1, r2, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 0)
        {
            uk1++;
            r1 = i;
        }
        else
        {
            uk2++;
            r2 = i;
        }
    }
    if (uk1 == 1)
        cout << r1 + 1;
    else
        cout << r2 + 1;
    return 0;
}