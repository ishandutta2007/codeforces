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
    int n, i, sum, m;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    i = 0;
    sum = 0;
    while (i < m && a[i] < 0)
    {
        sum += a[i];
        i++;
    }
    cout << -sum;
    return 0;
}