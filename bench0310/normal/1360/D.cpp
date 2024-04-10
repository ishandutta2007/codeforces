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
        int n,k;
        cin >> n >> k;
        int res=n;
        for(int i=1;i*i<=n;i++)
        {
            if((n%i)>0) continue;
            if(i<=k) res=min(res,n/i);
            if((n/i)<=k) res=min(res,i);
        }
        cout << res << "\n";
    }
    return 0;
}