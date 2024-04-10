#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e6+1;
char a[maxn];
ll n=1,sufsum[maxn],presum[maxn],b[maxn];

void read()
{
    char ch=getchar();
    while (ch!='\n' && ch!=-1)
    {
        a[n++]=ch;
        ch=getchar();
    }
}

void process()
{
    for (int i=1;i<n;i++)
    if (a[i]=='v' && a[i+1]=='v') b[i]=1;
    for (int i=1;i<=n;i++) presum[i]=presum[i-1]+b[i];
    for (int i=n;i;i--) sufsum[i]=sufsum[i+1]+b[i];
    ll ans=0;
    for (int i=2;i<n;i++)
        if (a[i]=='o') ans+=presum[i-1]*sufsum[i+1];
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}