#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
const ll base=73,mod=1e9+9;
string s;
int n;
ll a[N],h1[N],h2[N],powb[N];

void read()
{
    cin>>s;
    n=s.length();
    for (int i=1;i<=n;i++) a[i]=s[i-1]-'a'+1;
}

ll get_hash1(int l,int r)
{
    return (h1[r]-h1[l-1]*powb[r-l+1]+mod*mod)%mod;
}

ll get_hash2(int l,int r)
{
    return (h2[l]-h2[r+1]*powb[r-l+1]+mod*mod)%mod;
}

void process()
{
    for (int i=1;i<=n;i++) h1[i]=(h1[i-1]*base+a[i])%mod;
    h2[n+1]=0;
    for (int i=n;i;i--) h2[i]=(h2[i+1]*base+a[i])%mod;
    powb[0]=1;
    for (int i=1;i<=n;i++) powb[i]=powb[i-1]*base%mod;
    int l=1,r=n;
    while (l<r && a[l]==a[r]) l++,r--;
    if (l>=r)
    {
        cout<<s<<"\n";
        return;
    }
    int len1=0,len2=0;
    for (int i=l;i<=r;i++)
    {
        int mid=(l+i)/2;
        ll val1=get_hash1(l,mid),val2;
        if ((i-l+1)&1) val2=get_hash2(mid,i);
        else val2=get_hash2(mid+1,i);
        if (val1==val2) len1=max(len1,i-l+1);
        mid=(i+r)/2;
        val1=get_hash1(i,mid);
        if ((r-i+1)&1) val2=get_hash2(mid,r);
        else val2=get_hash2(mid+1,r);
        if (val1==val2) len2=max(len2,r-i+1);
    }
    for (int i=1;i<l;i++) cout<<s[i-1];
    if (len1>len2)
    {
        for (int i=1;i<=len1;i++) cout<<s[l+i-2];
    }
    else
    {
        for (int i=1;i<=len2;i++) cout<<s[r-len2+i-1];
    }
    for (int i=r+1;i<=n;i++) cout<<s[i-1];
    cout<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}