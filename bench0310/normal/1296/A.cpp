#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int c=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c+=(a&1);
        }
        if(c>0&&(!(c==n&&(n%2)==0))) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}