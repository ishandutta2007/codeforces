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
    string s, s1, s2;
    int n, i, uk, d, r1 = 1, r2 = 0;
    cin >> n;
    cin >> s1;
    for (i = 1; i < n; i++)
    {
        cin >> s;
        if (s1 == s)
            r1++;
        else
        {
            s2 = s;
            r2++;
        }
    }
    if (r1 > r2)
        cout << s1;
    else
        cout << s2;
    return 0;
}