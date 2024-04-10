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
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end(),greater<ll>());
        vector<int> b(k);
        for(int i=0;i<k;i++) cin >> b[i];
        sort(b.begin(),b.end());
        ll res=0;
        int idx=0;
        for(int x:b)
        {
            if(x==1) res+=(2*a[idx++]);
            else res+=(a[idx++]);
        }
        for(int x:b)
        {
            if(x==1) continue;
            idx+=(x-2);
            res+=a[idx++];
        }
        cout << res << "\n";
    }
    return 0;
}