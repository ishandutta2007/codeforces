#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll a[2201],n,i,j,m,k,sc;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    ll ans=0;
    for(i=0;i<k;i++)ans+=a[i];
    cout << ans << endl;
    return 0;
}