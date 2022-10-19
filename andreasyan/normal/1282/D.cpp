#include <bits/stdc++.h>
using namespace std;
const int N = 302;

char a[N];

int v;
int qry()
{
    cout << a << endl;
    int x;
    cin >> x;
    return x;
}

int main()
{
    for (int i = 0; i < 300; ++i)
        a[i] = 'a';
    int aa = 300 - qry();
    for (int i = 0; i < 300; ++i)
        a[i] = 'b';
    int bb = 300 - qry();
    int n = aa + bb;
    a[n] = 0;
    int v = aa;
    for (int i = 0; i < n - 1; ++i)
    {
        a[i] = 'a';
        int q = qry();
        if (q < v)
            v = q;
        else
            a[i] = 'b';
    }
    if (v == 1)
        a[n - 1] = 'a';
    qry();
    return 0;
}