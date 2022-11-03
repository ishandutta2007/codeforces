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
const int arr=5e5;
const int md=1e16;

int a[arr],sum[arr];

pair<int,int> pluss(pair<int,int> u, int a)
{
    u.sec+=a;
    while (u.fir>0 && u.sec<0)
    {
        u.sec+=md;
        u.fir--;
    }

    while (u.fir<0 && u.sec>0)
    {
        u.sec-=md;
        u.fir++;
    }

    bool ch=(u.fir<0 || u.sec<0);

    u.fir=abs(u.fir);
    u.sec=abs(u.sec);
    u.fir+=u.sec/md;
    u.sec%=md;

    if (ch)
    {
        u.fir=-u.fir;
        u.sec=-u.sec;
    }

    return(u);
}

signed main()
{
    map<int,int> mp;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    for (int i=n;i>=1;i--)
        sum[i]=sum[i+1]+a[i];

    pair<int,int> ans={0,0};

    for (int i=1;i<=n;i++)
    {
        ans=pluss(ans,-a[i]*(n-i+1));
        ans=pluss(ans,sum[i]);
        //cout<<i<<' '<<ans<<'\n';
        ans=pluss(ans,-mp[a[i]+1]);
        ans=pluss(ans,mp[a[i]-1]);
        mp[a[i]]--;
        //cout<<i<<' '<<ans<<'\n';
    }

    if (ans.fir<0 || ans.sec<0)
        cout<<'-';
    if (ans.fir!=0)
        cout<<abs(ans.fir);
    if (ans.fir==0)
    {
        cout<<abs(ans.sec);
        return(0);
    }
    ans.sec=abs(ans.sec);
    vector<int> vv;
    for(int i=0;i<16;i++)
    {
        
        vv.pb(ans.sec%10);
        ans.sec/=10;
    }
    reverse(vv.begin(),vv.end());
    for(auto i:vv)
    cout<<i;
}