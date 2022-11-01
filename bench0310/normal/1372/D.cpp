#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2*n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i+n]=a[i];
    }
    vector<ll> sum(2*n+1,0);
    for(int i=2;i<=2*n;i++) sum[i]=(i-2>=0?sum[i-2]:0)+a[i];
    ll res=0;
    for(int i=1;i+n-1<=2*n;i++) res=max(res,sum[i+n-1]-(i-2>=0?sum[i-2]:0));
    cout << res << "\n";
    return 0;
}