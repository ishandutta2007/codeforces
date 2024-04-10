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
    int sum = 0, n, i, n1, k;
    cin >> n;
    for (i = 2; i < n; i++)
    {
        n1 = n;
        while (n1 != 0)
        {
            sum += n1 % i;
            n1 /= i;
        }
    }
    k = n - 2;
    for (i = 2; i < sum; i++)
        while (sum % i == 0 && k % i == 0)
        {
            sum /= i;
            k /= i;
        }

    cout << sum  << "/" << k;

    return 0;
}