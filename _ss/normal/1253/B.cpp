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
const ll maxn=1e6+10,mod=1e9+7,inf=1e18;
int a[maxn],n;
int main()
{
 //   freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> ans,mem;
    int last=0,wait=0,check=1;
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        if (x>0)
        {
            if (a[x]==0) wait++,a[x]++;
            else check=0;
        }
        else
        {
            if (a[-x]==1) wait--,mem.pb(-x),a[-x]++;
            else check=0;
        }
        if (!wait)
        {
            for (int u : mem) a[u]=0;
            mem.clear();
            ans.pb(i-last);
            last=i;
        }
    }
    if (check && !wait && mem.empty())
    {
        cout<<ans.size()<<"\n";
        for (int u : ans) cout<<u<<" ";
    }
    else cout<<-1;
    return 0;
}