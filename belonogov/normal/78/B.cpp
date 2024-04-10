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
 //ROYGBIV
    int n, i, k;
    string s1, s2;
    cin >> n;
    cout << "ROYGBIV";
    n -= 7;
    s1 = "GBIV";
    s2 = "ROYG";
    k = n % 4;
    n -= k;
    for (i = 0; i < k; i++)
        cout << s1[i];
    for (i = 0; i < n; i++)
        cout << s2[i % 4];

    return 0;
}