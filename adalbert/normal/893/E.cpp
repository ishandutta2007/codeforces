#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll

typedef long long ll;
typedef double ld;
const int arr=3e6;

int rfact[arr],fact[arr];
const int  md=1e9+7;

int pow(int u, int step)
{
    if (step==0)
        return(1);
    if (step%2)
    {
        return(pow(u,step-1)*u%md);
    } else
    {
        int now=pow(u,step/2);
        return(now*now%md);
    }
}

int C(int a, int b)
{
    if (b>a)
        return(0);
    int res=fact[a];
    res*=rfact[b];
    res%=md;
    res*=rfact[a-b];
    res%=md;
    return(res);
}

int get(int a, int b)
{
    return(C(a+b-1,b));
}

int dp[arr][2];

int pred[arr];

signed main()
{
    for (int i=2;i<=2e6;i++)
    {
        if (pred[i]!=0)
            continue;

        for (auto j=i;j<=2e6;j+=i)
            if (pred[j]==0)
            pred[j]=i;
    }
    fast;
    fact[0]=1;
    for (int i=1;i<=2e6;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=md;
    }

    rfact[int(2e6)]=pow(fact[int(2e6)],md-2);
    for (int i=int(2e6)-1;i>=0;i--)
    {
        rfact[i]=rfact[i+1]*(i+1);
        rfact[i]%=md;
    }

    dp[0][0]=1;

    for (int i=0;i<=2e6;i++)
        for (int now=0;now<=1;now++)
        {
            dp[i+1][now]+=dp[i][now];
            dp[i+1][now]%=md;
            dp[i+1][!now]+=dp[i][now];
            dp[i+1][!now]%=md;
        }

    int n;
    cin>>n;
    while (n--)
    {
        int x,y;
        cin>>x>>y;

        int ans=dp[y][0];

        //cout<<x<<' '<<pred[x]<<'\n';

        while (pred[x]!=0)
        {
            int cnt=0;
            int pp=pred[x];
            while (pred[x]==pp)
            {
                x/=pp;
                cnt++;
            }
           // cout<<cnt<<'!'<<'\n';
            ans*=get(y,cnt);
            ans%=md;
        }
        //cout<<ans<<' '<<x<<'@'<<'\n';

        if (x!=1)
        {
            ans*=get(y,1);
            ans%=md;
        }
        cout<<ans<<'\n';
    }
}
/*
1
6 3
*/