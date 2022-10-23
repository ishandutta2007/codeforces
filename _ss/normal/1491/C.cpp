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
const int N=1e5+10;
ll n,a[N],cnt[N];
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
        ll res=0;
        for (int i=1;i<=n;i++) cin>>a[i],cnt[i]=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]-1>cnt[i]) res+=a[i]-1-cnt[i],cnt[i]=a[i]-1;
            if (a[i]+i>n) cnt[i]-=a[i]+i-n,a[i]=n-i;
            while (a[i]>1) cnt[i+a[i]]++,a[i]--,cnt[i]--;
            cnt[i+1]+=cnt[i];
        }
        cout<<res<<"\n";
    }
    return 0;
}