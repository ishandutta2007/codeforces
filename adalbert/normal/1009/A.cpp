#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ull
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ra,rb;

int ask(int a, int b)
{
    cout<<a<<' '<<b<<'\n';
    fflush(stdout);

    int res;
    cin>>res;
    if (res==0)
    {
        exit(0);
    }

    return(res);
}

int gr()
{
    int res=0;

    for (int i=0;i<5;i++)
    {
        res<<=16;
        res^=rand();
    }
    return(res);
}

int grsmall()
{
    return(rand()%10000);
}

int a[100000],b[100000];

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];

    int last=1;
    int ans=0;
    for (int i=1;i<=n;i++)
        if (last<=m && b[last]>=a[i])
    {
        ans++;
        last++;
    }

    cout<<ans;
}
/*
*/