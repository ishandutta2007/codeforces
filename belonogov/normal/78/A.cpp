#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//vector <int> a;
string  a[100];

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
    int i, j, n, res;
    string s;
    for (i = 0; i < 3; i++)
    {
        getline(cin, s);
        n = s.length();
        res = 0;
        for (j = 0; j < n; j++)
            if (s[j] == 'a' ||
                s[j] == 'e' ||
                s[j] == 'i' ||
                s[j] == 'o' ||
                s[j] == 'u'  )
                    res++;
        if (res != (i % 2) * 2 + 5)
        {
            cout << "NO";
            return 0;
        }
    }
    //a, e, i, o  u.


    cout << "YES";
    return 0;
}