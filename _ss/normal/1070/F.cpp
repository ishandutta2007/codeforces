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

vector<int> a[4];

bool cmp(int t1,int t2) {return t1>t2;}
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,can=0,d=0;
    cin>>n;
    for (int i=1,x;i<=n;i++)
    {
        string s;
        cin>>s>>x;
        if (s=="00") a[0].pb(x);
        if (s=="01") a[1].pb(x);
        if (s=="10") a[2].pb(x);
        if (s=="11") can+=x,d++;
    }
    for (int i=0;i<3;i++) sort(all(a[i]),cmp);
    for (int i=0;i<(int)min(a[1].size(),a[2].size());i++) can+=a[1][i]+a[2][i];
    for (int i=min(a[1].size(),a[2].size());i<(int)max(a[1].size(),a[2].size());i++)
        if (i<(int)a[1].size()) a[3].pb(a[1][i]);
        else a[3].pb(a[2][i]);
    int ans=can;
    for (int i=0;i<=3;i+=3)
        for (int j=1;j<(int)a[i].size();j++) a[i][j]+=a[i][j-1];
    if (a[3].size() && d) ans+=a[3][min((int)a[3].size(),d)-1];
    for (int i=0;i<min((int)a[0].size(),d);i++)
    {
        int tmp=can+a[0][i];
        if (a[3].size() && (d-i-1)) tmp+=a[3][min((int)a[3].size(),d-i-1)-1];
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}