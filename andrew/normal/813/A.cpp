#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
using namespace std;
vector <ll> tt[1000];
ll a[100001],b[1001],n,m,c,k,i,j;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> k;
        c+=k;
    }
    cin >> m;
    for(i=0;i<m;i++)
    {
        ll a1,a2;
        cin >> a1 >> a2;
        for(j=a1;j<=a2;j++)a[j]=1;
    }
    for(i=c;i<=100000;i++)if(a[i]==1)
    {
        cout <<  i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}