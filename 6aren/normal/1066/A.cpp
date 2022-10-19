#include <bits/stdc++.h>
using namespace std;
int ntest,l,v,a,b;
int main()
{
    cin >> ntest;
    while (ntest--)
    {
        cin >> l >> v >> a >> b;
        cout << l/v-(b/v)+(a-1)/v << endl;
    }
}