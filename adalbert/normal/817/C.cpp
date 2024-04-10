#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=300000+10;

int dp[30][210][3];

vector<int> parse(int u)
{
    vector<int> res;
    while (u!=0)
    {
        res.pb(u%10);
        u/=10;
    }
    reverse(res.begin(),res.end());
    return(res);
}

int getans(int s, int mx)
{
    //cout<<s<<' '<<mx<<' ';

    vector<int> vec=parse(mx);


    for (int i=0;i<=s;i++)
        for (int len=0;len<=20;len++)
        {
            dp[len][i][0]=0;
            dp[len][i][1]=0;
        }
    dp[0][0][1]=1;
    for (int i=0;i<vec.size();i++)
        for (int sum=0;sum<=s;sum++)
            for (int now=0;now<=9;now++)
            if (now<vec[i])
            {
                dp[i+1][sum+now][0]+=dp[i][sum][0]+dp[i][sum][1];
            } else
            if (now==vec[i])
            {
                dp[i+1][sum+now][1]+=dp[i][sum][1];
                dp[i+1][sum+now][0]+=dp[i][sum][0];
            } else
            {
                dp[i+1][sum+now][0]+=dp[i][sum][0];
            }
    return(dp[vec.size()][s][0]+dp[vec.size()][s][1]);
}

int get(int u)
{
    int ans=0;
    while (u!=0)
    {
        ans+=u%10;
        u/=10;
    }
    return(ans);
}

int get(int s, int l, int r)
{
    int ans=0;
    for (int i=l+1;i<=r;i++)
        ans+=(get(i)==s);
    return(ans);
}

signed main()
{
    int n,s;
    cin>>n>>s;
    vector<int> vec=parse(n);
    int ans=0;
    for (int i=0;i<=9*vec.size();i++)
    {
        //cout<<i<<' '<<n<<' '<<i+s-1<<' '<<max(ll(0),getans(i,n)-getans(i,i+s-1))<<' '<<get(i,i+s-1,n)<<'\n';
        ans+=max(ll(0),getans(i,n)-getans(i,i+s-1));
    }

    cout<<ans;
}