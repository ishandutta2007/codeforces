#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
int ans[maxn],aa[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,a,b,c;
    string s;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n>>a>>b>>c;
        char ch;
        for (int j=1;j<=n;j++)
        {
            cin>>ch;
            if (ch=='P') aa[j]=1;
            else if (ch=='S') aa[j]=2;
            else aa[j]=0;
        }
        int d=0;
        for (int j=1;j<=n;j++)
            if (aa[j]==0 && b) b--,ans[j]=1,d++;
            else if (aa[j]==1 && c) c--,ans[j]=2,d++;
            else if (aa[j]==2 && a) a--,ans[j]=3,d++;
            else ans[j]=0;
        for (int j=1;j<=n;j++)
            if (!ans[j])
            {
                if (a)
                {
                    a--;
                    ans[j]=3;
                }
                else if (b)
                {
                    b--;
                    ans[j]=1;
                }
                else ans[j]=2;
            }
        if (d>=(n+1)/2)
        {
            cout<<"YES\n";
            for (int j=1;j<=n;j++)
                if (ans[j]==1) cout<<"P";
                else if (ans[j]==2) cout<<"S";
                else cout<<"R";
            cout<<endl;
        }
        else cout<<"NO\n";
    }
    return 0;
}