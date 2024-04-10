#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,z;
    cin >> n >> z;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int l=0,r=n/2+1;
    while(l<r-1)
    {
        int m=(l+r)/2;
        bool ok=1;
        for(int i=0;i<m;i++) ok&=(v[n-m+i]-v[i]>=z);
        if(ok) l=m;
        else r=m;
    }
    cout << l << "\n";
    return 0;
}