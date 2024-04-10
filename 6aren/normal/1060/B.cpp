#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin >> n;
    int res=0;
    while (n!=0)
    {
        int t=n%10;
        if (n-t>=10 && t!=9)
        {
            res+=t+10;
            n=n-t-10;
            n=n/10;
        }
        else
        {
            res+=t;
            n=n-t;
            n=n/10;
        }
    }
    cout << res;
}