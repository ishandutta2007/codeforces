#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

string s[N],t[N];
int m,n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=m;i++) cin>>t[i];
    int q;
    cin>>q;
    for (int i=1,x;i<=q;i++)
    {
        cin>>x;
        cout<<s[(x-1)%n+1]<<t[(x-1)%m+1]<<"\n";
    }
    return 0;
}