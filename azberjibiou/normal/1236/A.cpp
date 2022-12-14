#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int stone=0;
        int n=min(b, c/2);
        b-=n;
        stone+=n*3;
        int m=min(a, b/2);
        stone+=m*3;
        cout << stone << '\n';
    }
}