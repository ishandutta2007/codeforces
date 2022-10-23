#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;

int a[N],n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        int l=0,r=0;
        for (int i=1;i<n;i++)
            if (abs(a[i]-a[i+1])>=2) l=i,r=i+1;
        if (!l) cout<<"NO\n";
        else cout<<"YES\n"<<l<<" "<<r<<"\n";
    }
    return 0;
}