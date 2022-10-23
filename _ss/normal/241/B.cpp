#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,mod=1e9+7,bit=30;
int n,a[N],cnt_bit[N][30],cnt[N];
ll m;

void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
}

pii cal(int val,int sl)
{
    unordered_map<int,int> id;
    int t=1;
    ll res=0,res2=0;
    for (int i=1;i<=n;i++)
    {
        int key=a[i]>>(bit-sl);
        if (!id[key]) id[key]=t++;
        int tmp=id[key ^ val];
        if (tmp)
        {
            for (int j=0;j<bit;j++)
                if ((a[i]>>j)&1) res=(res+(ll)(1<<j)*(cnt[tmp]-cnt_bit[tmp][j]))%mod;
                else res=(res+(ll)(1<<j)*cnt_bit[tmp][j])%mod;
                res2+=cnt[tmp];
        }
        tmp=id[key];
        for (int j=0;j<bit;j++)
            if ((a[i]>>j)&1) cnt_bit[tmp][j]++;
        cnt[tmp]++;
    }
    for (int i=1;i<t;i++)
    {
        for (int j=0;j<bit;j++) cnt_bit[i][j]=0;
        cnt[i]=0;
    }
    return mp(res,res2);
}

int solve()
{
    ll res=0,len=0,val=0;
    while (m && len<bit)
    {
        len++;
        val<<=1;
        pii tmp=cal(val+1,len);
        if (tmp.se==m) return (res+tmp.fi)%mod;
        if (tmp.se<m)
        {
            m-=tmp.se;
            res=(res+tmp.fi)%mod;
        }
        else val++;
    }
    if (m>0) res=(res+val*m)%mod;
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    cout<<solve();
    return 0;
}