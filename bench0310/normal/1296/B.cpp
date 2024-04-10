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
        int s;
        cin >> s;
        int res=0;
        while(s>=10)
        {
            int x=(s-(s%10));
            int y=(s/10);
            s-=x;
            s+=y;
            res+=x;
        }
        res+=s;
        cout << res << "\n";
    }
    return 0;
}