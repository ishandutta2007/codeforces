#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(),a.end());
    vector<int> p(n,0);
    for(int i=0;i<n;i++) p[i]=a[i][1];
    vector<array<int,2>> res;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(p[j]>p[j+1])
            {
                res.push_back({p[j+1],p[j]});
                swap(p[j],p[j+1]);
            }
        }
    }
    cout << res.size() << "\n";
    for(auto [i,j]:res) cout << i << " " << j << "\n";
    return 0;
}