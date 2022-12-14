#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
using namespace std;
vector <ll> tt[1000];
ll a[1000],b[1000],stn,i,j,k,n,m,sc,c;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<k;i++)cin >> b[i];
    sort(b,b+k);
    reverse(b,b+k);
    for(i=0;i<n;i++)if(a[i]==0)
    {
        a[i]=b[stn];
        stn++;
    }
    for(i=1;i<n;i++)if(a[i]<=a[i-1])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}