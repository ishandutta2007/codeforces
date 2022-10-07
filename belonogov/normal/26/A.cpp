#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//vector <int> a;
int  a[10000];
int f(int a)
{
    int res = 0, i;
    for (i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            res++;
            while (a % i == 0)
                a /= i;
        }
    }
    if (res == 2)
        return 1;
    else
        return 0;
}


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
    int n, i, res = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
        res += f(i);
    cout << res;
    return 0;
}