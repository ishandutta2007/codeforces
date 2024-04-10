#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int a=n-(k-1);
        if((a%2)==1&&a>0)
        {
            cout << "YES\n";
            for(int i=0;i<k-1;i++) cout << "1 ";
            cout << a << "\n";
            continue;
        }
        a=n-2*(k-1);
        if((a%2)==0&&a>0)
        {
            cout << "YES\n";
            for(int i=0;i<k-1;i++) cout << "2 ";
            cout << a << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}