#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,x[105],y[105];
    cin >> n  >> d;
    bool check;
    int m;
    cin >> m;
    for (int i=1;i<=m;i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i=1;i<=m;i++)
    {
        if ((x[i]-y[i])<=d && (x[i]-y[i]) >=-d && (x[i]+y[i]) >= d && (x[i]+y[i]) <=2*n-d )
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}