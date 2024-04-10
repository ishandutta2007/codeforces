#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<bool> v(m,0);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(v[a[i]%m]==1)
        {
            cout << "0\n";
            return 0;
        }
        v[a[i]%m]=1;
    }
    ll res=1;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) res=(res*abs(a[j]-a[i]))%m;
    cout << res << "\n";
    return 0;
}