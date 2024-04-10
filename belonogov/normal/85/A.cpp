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
    int n, i;
    cin >> n;
    if (n % 2 == 1)
    {
        for (i = 0; i < (n - 1) / 2; i++)
            if (i % 2 == 0)
                cout << "aa";
            else
                cout << "bb";
        cout << "x\n";
        for (i = 0; i < (n - 1) / 2; i++)
            if (i % 2 == 0)
                cout << "cc";
            else
                cout << "dd";
        cout << "x\n";
    /////////////
        cout << "y";
           for (i = 0; i < (n - 1) / 2; i++)
            if (i % 2 == 0)
                cout << "aa";
            else
                cout << "bb";
        cout << "\ny";
        for (i = 0; i < (n - 1) / 2; i++)
            if (i % 2 == 0)
                cout << "cc";
            else
                cout << "dd";
    }

    if (n % 2 == 0)
    {
        for (i = 0; i < n / 2; i++)
            if (i % 2 == 0)
                cout << "aa";
            else
                cout << "bb";
        cout << "\nx";
        for (i = 0; i < n / 2 - 1; i++)
            if (i % 2 == 0)
                cout << "dd";
            else
                cout << "ee";
        cout << "y";
        cout << "\nx";
        for (i = 0; i < n / 2 - 1; i++)
            if (i % 2 == 0)
                cout << "ee";
            else
                cout << "dd";
        cout << "y\n";

        for (i = 0; i < n / 2; i++)
            if (i % 2 == 0)
                cout << "aa";
            else
                cout << "bb";

    }
    return 0;
}