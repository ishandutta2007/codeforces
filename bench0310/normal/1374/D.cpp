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
        map<int,ll> m;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            if((a%k)>0) m[k-(a%k)]++;
        }
        ll res=0;
        for(auto [d,c]:m) res=max(res,(c-1)*k+d+1);
        cout << res << "\n";
    }
    return 0;
}