#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v[4];
    for(int i=0;i<n;i++)
    {
        int t,a,b;
        cin >> t >> a >> b;
        v[2*a+b].push_back(t);
    }
    for(int i=1;i<=2;i++) sort(v[i].begin(),v[i].end());
    for(int i=0;i<(int)min(v[1].size(),v[2].size());i++) v[3].push_back(v[1][i]+v[2][i]);
    sort(v[3].begin(),v[3].end());
    if((int)v[3].size()<k) cout << "-1\n";
    else
    {
        int res=0;
        for(int i=0;i<k;i++) res+=v[3][i];
        cout << res << "\n";
    }
    return 0;
}