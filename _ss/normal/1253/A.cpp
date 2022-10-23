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
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
int n,a[maxn],b[maxn];
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
        for (int i=1;i<=n;i++) cin>>b[i];
        int check=1;
        for (int i=1;i<=n;i++)
            if (a[i]>b[i])
            {
                check=0;
                break;
            }
            else if (a[i]<b[i])
            {
                int val=b[i]-a[i];
                for (int j=i+1;j<=n;j++)
                    if (a[j]==b[j])
                    {
                        for (int u=j+1;u<=n;u++)
                            if (a[u]!=b[u]) check=0;
                        break;
                    }
                    else if (a[j]>b[j])
                    {
                        check=0;
                        break;
                    }
                    else if (a[j]+val!=b[j])
                    {
                        check=0;
                        break;
                    }
                break;
            }
        if (check) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}