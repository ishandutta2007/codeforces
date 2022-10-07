#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//vector <int> a;
int  b[10000];

int f(int a)
{
    int i;
    int res = 0, uk = 0;
    while (a != 0)
    {
        if (a % 10 != 0)
            b[uk++] = a%10;
        a /= 10;
    }
    for (i = uk - 1; i >= 0; i--)
        res = res * 10 + b[i];

    return res;
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
    int a, b1, c;
    cin >> a >> b1;
    c = a + b1;
    if (f(a) + f(b1) == f(c))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}