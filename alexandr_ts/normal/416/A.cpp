#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

typedef long long ll;
typedef long double ld;

int a[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    int k;
    char ch;
    int l = -1e9 - 1;
    int r = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> k >> ch;
        //cout << s << " " <<k << " " << ch << endl;
        if (s == ">")
            if (ch == 'Y')
                l = max(l, k + 1);
            else
                r = min(r, k);
        if (s == ">=")
            if (ch == 'Y')
                l = max(l, k);
            else
                r =  min(r, k - 1);
        if (s == "<")
            if (ch == 'Y')
                r = min(r, k - 1);
            else
                l = max(l, k);
        if (s == "<=")
            if (ch == 'Y')
                r = min(r, k);
            else
                l = max(l, k + 1);
    }
    if (l > r)
        cout << "Impossible";
    else
        if (l != -1e9 - 1)
            cout << l;
        else
            if (r != 1e9 + 1)
                cout << r;
            else
                cout << l + 1;


    return 0;
}