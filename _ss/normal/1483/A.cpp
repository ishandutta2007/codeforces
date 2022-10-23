#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=2e5+10;
int n,m,cnt[N],c[N];
vi vt[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=1;i<=m;i++)
        {
            int len;
            cin>>len;
            vt[i].clear();
            for (int j=1,x;j<=len;j++) cin>>x,vt[i].eb(x);
            c[i]=vt[i][0];
            cnt[c[i]]++;
        }
        int d=-1,lim=(m+1)/2;
        for (int i=1;i<=n;i++)
            if (cnt[i]>lim) d=i;
        if (d!=-1)
        {
            for (int i=1;i<=m && cnt[d]>lim;i++)
                if (c[i]==d && (int)vt[i].size()>1) c[i]=vt[i][1],cnt[d]--;
            if (cnt[d]<=lim) d=-1;
        }
        if (d==-1)
        {
            cout<<"YES\n";
            for (int i=1;i<=m;i++) cout<<c[i]<<" ";
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}