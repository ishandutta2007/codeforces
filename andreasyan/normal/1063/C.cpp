#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "0 0" << endl;
    string ss;
    cin >> ss;
    int l = 1, r = 1000000000;
    for (int i = 0; i < n - 1; ++i)
    {
        int m = (l + r) / 2;
        cout << m << ' ' << m << endl;
        string s;
        cin >> s;
        if (s == ss)
            l = m + 1;
        else
            r = m - 1;
    }
    cout << l - 1 << ' ' << l << ' ' << l << ' ' << l - 1 << endl;
    return 0;
}