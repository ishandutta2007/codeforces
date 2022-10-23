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
const ll mod=998244353;
int n,a[N],L[N];
ll ps[N];

ll solve(int l,int r,ll lim,int mark=1)
{
    if (l>r+1) return 0;
    ll sum_p=0,res=0;
    for (int len=mark;len<=r-l+1;len++)
    {
        if (len) sum_p+=a[r-len+1];
        if (sum_p>=lim) res++;
        int sta=r-len-1;
        if (sta<l) continue;
        int low=0,high=(sta-l)/2+1,best=0;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (ps[sta]-ps[sta-mid*2]+sum_p<lim) low=mid+1,best=mid;
            else high=mid-1;
        }
        res+=(sta-l)/2+1-best;
    }
    return res;
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
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        ll ans=0,sum=0;
        for (int i=1;i<=n;i++) sum+=a[i];
        ll sum_p=0;
        for (int i=1;i<=n;i++)
        {
            sum_p+=a[i];
            if (sum_p>sum-sum_p) ans++;
        }
        //cout<<ans<<"\n";
        ps[1]=a[1];
        for (int i=2;i<=n;i++) ps[i]=ps[i-2]+a[i];
        ans+=solve(3,n-1,sum/2+1-a[1]-a[n],0);
        //cout<<ans<<"\n";
        ans+=solve(3,n-1,sum/2+1-a[1]);
        //cout<<ans<<"\n";
        ans+=solve(2,n-1,sum/2+1-a[n],0);
        //cout<<ans<<"\n";
        ans+=solve(2,n-1,sum/2+1);
        cout<<ans%mod<<"\n";
    }
    return 0;
}