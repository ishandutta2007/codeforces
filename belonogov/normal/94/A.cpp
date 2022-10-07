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
    int i, j;
    string s, s1;
    getline(cin, s);
    for (i = 0; i < 10; i++)
        getline(cin, a[i]);

    for (i = 0; i < 8; i++)
    {
        s1 = "";
        for (j = i * 10; j < (i + 1) * 10; j++)
            s1 += s[j];
        for (j = 0; j < 10; j++)
            if (s1 == a[j])
                cout << j;
    }


    return 0;
}