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
const int N=2e6;
int a[N],ps[N],mark[N];

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
        string s;
        cin>>n>>k>>s;
        for (int i=1;i<=n;i++) a[i]='1'-s[i-1],ps[i]=ps[i-1]+a[i];
        vi vt;
        for (int i=1;i<=n-k+1;i++)
        {
            int l=i,r=i+k-1-20;
            if (l<=r && ps[r]-ps[l-1]>0) continue;
            int val=0;
            for (int j=max(i,i+k-20);j<=i+k-1;j++) val=(val<<1)+a[j];
            vt.eb(val);
            mark[val]=1;
        }
        int mask=-1;
        for (int i=0;i<(1<<(min(k,20)));i++)
            if (!mark[i])
            {
                mask=i;
                break;
            }
        for (int x : vt) mark[x]=0;
        if (mask==-1)
        {
            cout<<"NO\n";
            continue;
        }
        vi ans;
        for (int i=0;i<min(k,20);i++)
            if ((mask>>i)&1) ans.eb(1);
            else ans.eb(0);
        for (int i=20;i<k;i++) ans.eb(0);
        reverse(all(ans));
        cout<<"YES\n";
        for (int x : ans) cout<<x;
        cout<<"\n";
    }
    return 0;
}