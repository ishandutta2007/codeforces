#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
using namespace std;
vector <ll> tt[10000];
ll n,m,a[1000],b[1000],sc,i;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<m;i++)cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(i=0;i<n;i++)
        for(ll j=0;j<m;j++)if(a[i]==b[j])
    {
        cout << a[i] << endl;
        return 0;
    }
    cout << min(a[0],b[0]) << max(a[0],b[0]) << endl;
   return 0;
}