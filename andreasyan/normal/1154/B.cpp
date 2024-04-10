#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (s.size() > 3)
    {
        cout << -1 << endl;
        return 0;
    }
    if (s.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (s.size() == 2)
    {
        if ((*(--s.end()) - *(s.begin())) % 2 == 1)
            cout << *(--s.end()) - *(s.begin()) << endl;
        else
            cout << (*(--s.end()) - *(s.begin())) / 2 << endl;
        return 0;
    }
    if (*(++s.begin()) - *s.begin() == *(--s.end()) - *(++s.begin()))
    {
        cout << *(++s.begin()) - *s.begin() << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}