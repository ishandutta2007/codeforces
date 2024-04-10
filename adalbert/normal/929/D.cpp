#include<bits/stdc++.h>

using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=3e5;

int n,s,f,k[arr],g[arr];
int last[arr],goup[arr],godown[arr];
bool use[arr];

int solve(int s, int f)
{
    if (f==0 || f==n+1)
    {
        cout<<-1;
        exit(0);
    }
    if (use[f])
    {
        cout<<-1;
        exit(0);
    }
    use[f]=1;
    if (s==f)
        return(0);
    if (s<f)
    {
        int mn=godown[f];
        return(solve(s,mn)+abs(f-mn));
    } else
    if (s>f)
    {
        int mx=goup[f];
        return(solve(s,mx)+abs(mx-f));
    }
}

signed main()
{
    cin>>n>>s>>f;

    for (int i=1;i<n;i++)
        cin>>g[i];

    for (int i=1;i<=n;i++)
        cin>>k[i];

    godown[s]=s;

    for (int i=1;i<=n;i++)
    {

        if (i>s)
            godown[i]=min(godown[i-1],last[g[i-1]]);
        last[k[i]]=i;
    }

    for (int i=1;i<=1e5;i++)
        last[i]=n+1;

    goup[s]=s;
    for (int i=n;i>=1;i--)
    {
        if (i<s)
            goup[i]=max(goup[i+1],last[g[i]]);
        last[k[i]]=i;
    }

    cout<<solve(s,f);
}

/*
2 1 2
1
2 1

*/