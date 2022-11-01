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
        vector<ll> a(n);
        ll res=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if((i&1)==0)
            {
                res+=a[i];
                a[i]=-a[i];
            }
        }
        vector<ll> now(2,0);
        now[0]=(1ll<<60);
        ll d=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            d=max(d,sum-now[i&1]);
            now[i&1]=min(now[i&1],sum);
        }
        cout << res+d << "\n";
    }
    return 0;
}