#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll a[100001],i,j,n,m;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll ans=0;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=0;i<m;i++)
    {
      ll y,x;
      cin >> y >> x;
      ans+=min(a[y],a[x]);
    }
  cout << ans << endl;
  return 0;
}