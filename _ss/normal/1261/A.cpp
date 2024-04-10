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
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
char a[maxn];

void rev(int l,int r)
{
    for (int i=1;i<=(r-l+1)/2;i++) swap(a[l+i-1],a[r-i+1]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        string tt;
        cin>>n>>k>>tt;
        for (int i=1;i<=n;i++) a[i]=tt[i-1];
        vector<pii> ans;
        int sl=n/2-k+1;
        for (int i=1;i<=sl;i++)
        {
            if (a[i]=='(') continue;
            int vt=0;
            for (int j=i+1;j<=n;j++)
                if (a[j]=='(')
                {
                    vt=j;
                    break;
                }
            ans.pb(mp(i,vt));
            rev(i,vt);
        }
        for (int i=sl+1;i<=sl*2;i++)
        {
            if (a[i]==')') continue;
            int vt=0;
            for (int j=i+1;j<=n;j++)
                if (a[j]==')')
                {
                    vt=j;
                    break;
                }
            ans.pb(mp(i,vt));
            rev(i,vt);
        }
        for (int i=sl*2+1;i<=n;i++)
            if (i&1)
            {
                if (a[i]=='(') continue;
                int vt=0;
                for (int j=i+1;j<=n;j++)
                    if (a[j]=='(')
                    {
                        vt=j;
                        break;
                    }
                ans.pb(mp(i,vt));
                rev(i,vt);
            }
            else
            {
                if (a[i]==')') continue;
                int vt=0;
                for (int j=i+1;j<=n;j++)
                    if (a[j]==')')
                    {
                        vt=j;
                        break;
                    }
                ans.pb(mp(i,vt));
                rev(i,vt);
            }
        cout<<ans.size()<<"\n";
        for (pii x : ans) cout<<x.fi<<" "<<x.se<<"\n";
    }
    return 0;
}