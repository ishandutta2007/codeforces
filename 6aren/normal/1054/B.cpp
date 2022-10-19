#include<bits/stdc++.h>
using namespace std;
int n,s,a;
int main()
{
    cin >> n;
    s=-1;
    for (int i=1;i<=n;i++)
    {
        cin >> a;
        if (a>s+1)
        {
            cout << i;
            return 0;
        }
        s=max(s,a);
    }
    cout << -1;
    return 0;
}