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
const int N=2e5+10,V=1e7;
int lp[V+10];

void sieve()
{
    for (int i=2;i<=V;i++)
        if (!lp[i])
            for (int j=i;j<=V;j+=i)
                if (!lp[j]) lp[j]=i;
}

int compress(int x)
{
    int res=1;
    while (x>1)
    {
        int tmp=lp[x],d=0;
        while (tmp==lp[x])
        {
            x/=tmp;
            d^=1;
        }
        if (d) res*=tmp;
    }
    return res;
}

int a[N],n,k,mr[N][22],dp[N][22];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i],a[i]=compress(a[i]);
        for (int change=0;change<=k;change++)
        {
            int j=1,cn=0;
            unordered_map<int,int> cnt;
            cnt.max_load_factor(0.25);
            for (int i=1;i<=n;i++)
            {
                while (j<=n && cn<=change)
                {
                    if (cnt[a[j]]>0) cn++;
                    if (cn>change)
                    {
                        cn--;
                        break;
                    }
                    cnt[a[j]]++;
                    j++;
                }
                mr[i][change]=j-1;
                if (cnt[a[i]]>1) cn--;
                cnt[a[i]]--;
            }
        }
        for (int i=0;i<=n;i++)
            for (int j=0;j<=k;j++) dp[i][j]=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=k;j++)
                for (int d=0;d<=k-j;d++)
                    dp[i+1][j+d]=max(dp[i+1][j+d],mr[dp[i][j]+1][d]);
        int res=n;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=k;j++)
                if (dp[i][j]==n) res=min(res,i);
        cout<<res<<"\n";
    }
    return 0;
}