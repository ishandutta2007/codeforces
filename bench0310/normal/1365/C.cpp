#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> one(n+1,0),two(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        one[a]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int b;
        cin >> b;
        two[b]=i;
    }
    vector<int> v(n,0);
    for(int i=1;i<=n;i++) v[(two[i]-one[i]+n)%n]++;
    int res=0;
    for(int i=0;i<n;i++) res=max(res,v[i]);
    cout << res << "\n";
    return 0;
}