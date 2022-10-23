#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=5e5+10,inf=1e8;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll d=0,sl=0;
    while (sl<m)
    {
        d++;
        sl+=(d-1)/2;
    }
    if (d>n)
    {
        cout<<-1;
        return 0;
    }
    if (sl==m)
    {
        for (int i=1;i<=d;i++) cout<<i<<" ";
        for (int i=d+1;i<=n;i++) cout<<inf+(i-n)*5001<<" ";
        return 0;
    }
    sl-=(d-1)/2;
    int k=0;
    while (sl+(d-k-1)/2>m) k++;
    for (int i=1;i<d;i++) cout<<i<<" ";
    cout<<d+k<<" ";
    for (int i=d+1;i<=n;i++) cout<<inf+(i-n)*5001<<" ";
    return 0;
}