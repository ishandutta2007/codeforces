#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,c;
    cin>>r>>c;
    if (r==1 && c==1)
    {
        cout<<0;
        return 0;
    }
    if (r==1)
    {
        for (int i=1;i<=c;i++) cout<<i+1<<" ";
        return 0;
    }
    if (c==1)
    {
        for (int i=1;i<=r;i++) cout<<i+1<<"\n";
        return 0;
    }
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++) cout<<j*(c+i)<<" ";
        cout<<"\n";
    }
    return 0;
}