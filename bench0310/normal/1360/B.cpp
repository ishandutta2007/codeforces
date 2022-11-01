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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.end());
        int res=v[1]-v[0];
        for(int i=1;i<n;i++) res=min(res,v[i]-v[i-1]);
        cout << res << "\n";
    }
    return 0;
}