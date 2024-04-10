#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=2e6+10,msiz=2,mod=998244353,inf=1e18;
char a[maxn],l[maxn],r[maxn],b[maxn];
int z[maxn],siza,sizl,sizr,check1[maxn],check2[maxn],flag1[maxn],flag2[maxn];
ll f[maxn];

void read(char s[],int &siz)
{
    string st;
    cin>>st;
    siz=st.length();
    for (int i=0;i<siz;i++) s[i+1]=st[i];
}

void zf(char s1[],char s2[],int siz1,int siz2)
{
    int siz=siz1+siz2;
    for (int i=1;i<=siz1;i++) b[i]=s1[i];
    for (int i=1;i<=siz2;i++) b[i+siz1]=s2[i];
    int t=1,ra=1;
    for (int i=2;i<=siz;i++)
    {
        if (i<=ra) z[i]=min(ra-i+1,z[i-t+1]); else z[i]=0;
        while (i+z[i]<=siz && b[i+z[i]]==b[z[i]+1]) z[i]++;
        if (i+z[i]-1>ra)
        {
            ra=i+z[i]-1;
            t=i;
        }
    }
}

void process()
{
    zf(l,a,sizl,siza);
    for (int i=1;i<=siza;i++)
        if (z[i+sizl]>=sizl || a[z[i+sizl]+i]>=l[z[i+sizl]+1]) check1[i]=1;
    zf(r,a,sizr,siza);
    for (int i=1;i<=siza;i++)
        if (z[i+sizr]>=sizr || a[z[i+sizr]+i]<=r[z[i+sizr]+1]) check2[i]=1;
    f[0]=1;
    ll k=0;
    for (int i=sizl;i<=siza;i++)
    {
        if (check1[i-sizl+1] && a[i-sizl+1]!='0') k=(k+f[i-sizl])%mod,flag1[i-sizl]=1;
        if (i-sizl>0 && !flag1[i-sizl-1] && a[i-sizl]!='0') k=(k+f[i-sizl-1])%mod;
        if (i-sizr>=0 && !check2[i-sizr+1] && a[i-sizr+1]!='0') k=(k-f[i-sizr]+mod)%mod,flag2[i-sizr]=1;
        if (i-sizr>0 && !flag2[i-sizr-1] && a[i-sizr]!='0') k=(k-f[i-sizr-1]+mod)%mod;
        if (a[i]=='0' && check1[i]) f[i]=(k+f[i-1])%mod;
        else f[i]=k;
        //cout<<f[i]<<endl;
    }
    cout<<f[siza];
    //for (int i=1;i<=siza;i++) cout<<check2[i]<<endl;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(a,siza);
    read(l,sizl);
    read(r,sizr);
    a[siza+1]=l[sizl+1]=r[sizr+1]='0';
    process();
    return 0;
}