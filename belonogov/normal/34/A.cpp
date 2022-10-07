#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//vector <int> a;
int  a[10000];
int mod (int a, int  b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
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
    int n, i, uk, d;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    d = 10000;
    for (i = 0; i < n; i++)
        if (mod(a[i], a[(i + 1) % n]) < d)
        {
            d = mod(a[i], a[(i + 1) % n]);
            uk = i;
        }
    cout << uk + 1 << " " << (uk + 1) % n + 1;
    return 0;
}