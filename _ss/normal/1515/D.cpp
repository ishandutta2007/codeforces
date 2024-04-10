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
const int N = 1e6 + 10;
int cnt[N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=1,x;i<=l;i++) cin>>x,cnt[x]++;
        for (int i=1,x;i<=r;i++) cin>>x,cnt[x]--;
        int d = 0;
        for (int i=1;i<=n;i++) d+=cnt[i];
        int res=0;
        d/=2;
        if (d > 0)
            for (int i=1;i<=n && d>0;i++)
                if (cnt[i]>0)
                {
                    if (cnt[i]/2>d) cnt[i]-=2*d,res+=d,d=0;
                    else d-=cnt[i]/2,res+=cnt[i]/2,cnt[i]&=1;
                }
        if (d < 0)
            for (int i=1;i<=n && d<0;i++)
                if (cnt[i]<0)
                {
                    int tmp=-cnt[i]/2;
                    if (tmp>-d) cnt[i]+=-2*d,res+=-d,d=0;
                    else d+=tmp,res+=tmp,cnt[i]+=2*tmp;
                }
        d=0;
        for (int i=1;i<=n;i++) d+=cnt[i];
        res+=abs(d/2);
        l=0;
        r=0;
        for (int i=1;i<=n;i++)
            if (cnt[i]>0) l+=cnt[i];
            else r-=cnt[i];
        cout<<res+(l+r)/2<<"\n";
    }
    return 0;
}