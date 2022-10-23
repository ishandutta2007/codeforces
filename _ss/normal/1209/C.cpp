#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;
vector<int> a[10];
int mark[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        char c;
        cin>>n;
        for (int j=0;j<=9;j++) a[j].clear();
        for (int j=1;j<=n;j++)
        {
            cin>>c;
            a[(c-'0')].pb(j);
        }
        int mr=0,k=1,check=1;
        for (int j=0;j<=9;j++)
        if (a[j].size())
        {
            if (a[j][0]>mr)
            {
                for (int u=0;u<a[j].size();u++) mark[a[j][u]]=k;
                mr=a[j].back();
            }
            else if (k==1)
            {
                int tmp;
                for (int u=0;u<a[j].size();u++)
                    if (a[j][u]>mr) mark[a[j][u]]=k;
                    else mark[a[j][u]]=k+1,tmp=a[j][u];
                mr=tmp;
                k++;
            }
            else
            {
                check=0;
                break;
            }
        }
        if (!check) cout<<"-"<<endl;
        else
        {
            for (int j=1;j<=n;j++) cout<<mark[j];
            cout<<endl;
        }
    }
    return 0;
}