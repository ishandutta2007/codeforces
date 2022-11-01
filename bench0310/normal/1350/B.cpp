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
        int res=0;
        vector<int> d(n+1,1);
        for(int i=1;i<=n;i++)
        {
            res=max(res,d[i]);
            for(int j=2*i;j<=n;j+=i) if(a[i]<a[j]) d[j]=max(d[j],d[i]+1);
        }
        cout << res << "\n";
    }
    return 0;
}