#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=1e6+100;
const int md=1e9+7;
const int base=1039;

int n,m,k;

int pred[arr],a[arr];
bool use[arr];

int solve(int u)
{
    int last=0;
    int cnt=0;
    while (last<n)
    {
        int start=last;
        last+=u;
        if (last<n)
        last=pred[last];
        if (last==start)
            return(1e18);
        cnt++;

    }
    return(cnt);
}

signed main()
{
    fast;
    cin>>n>>m>>k;

    for (int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        use[x]=1;
    }

    for (int i=1;i<=k;i++)
        cin>>a[i];

    if (use[0])
    {
        cout<<-1;
        return(0);
    }

    for (int i=1;i<n;i++)
        if (use[i])
        pred[i]=pred[i-1]; else
        pred[i]=i;


    int ans=1e18;


    for (int i=1;i<=k;i++)
    {
        int now=solve(i);
        if (now!=1e18)
        ans=min(ans,now*a[i]);

    }


    if (ans==1e18)
        cout<<-1; else
    cout<<ans;
}
/*
*/