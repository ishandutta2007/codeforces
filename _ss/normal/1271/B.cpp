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
int a[N],b[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    char ch;
    for (int i=1;i<=n;i++)
    {
        cin>>ch;
        a[i]=(ch=='W');
        b[i]=a[i];
    }
    vector<int> ans,ans2;
    for (int i=1;i<n;i++)
        if (a[i]) a[i]^=1,a[i+1]^=1,ans.pb(i);
    if (!a[n])
    {
        cout<<ans.size()<<"\n";
        for (int x : ans) cout<<x<<" ";
        return 0;
    }
    for (int i=1;i<n;i++)
        if (!b[i]) b[i]^=1,b[i+1]^=1,ans2.pb(i);
    if (b[n])
    {
        cout<<ans2.size()<<"\n";
        for (int x : ans2) cout<<x<<" ";
        return 0;
    }
    cout<<-1;
    return 0;
}