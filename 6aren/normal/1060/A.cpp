#include <bits/stdc++.h>
using namespace std;
int n;
string a;
int main()
{
    cin >> n;
    cin >> a;
    int cnt=0;
    for (int i=0;i<=n-1;i++)
    {
        int u;
        u=(int) a[i]-'0';
        if (u==8) cnt++;
    }
    cout << min(cnt,n/11);
}