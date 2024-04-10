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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> b(n+1,0);
        for(int i=2;i<=n;i++) cin >> b[i];
        cin >> b[1];
        bool ok=1;
        ll mx=0;
        ll sum=0;
        for(int i=1;i<=2*n;i++)
        {
            int p=(i-((i>n)*n));
            ok&=(b[p]+sum-mx>=0);
            sum+=(b[p]-a[p]);
            mx=max(mx,sum);
        }
        ok&=(sum>=0);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}