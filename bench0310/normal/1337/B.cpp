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
        int x,n,m;
        cin >> x >> n >> m;
        bool ok=((x+9)/10<=m);
        for(int i=1;i<=n;i++)
        {
            x=(x/2)+10;
            ok|=((x+9)/10<=m);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}