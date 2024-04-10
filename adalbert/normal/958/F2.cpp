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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef long double ld;

const int arr=3e5;
int a[arr],k[arr],cnt[arr];
int good=0;
void add(int u)
{
    cnt[u]++;
    if (cnt[u]==k[u])
        good++;
}

void dell(int u)
{
    if (cnt[u]==k[u])
        good--;
    cnt[u]--;
}

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int len=0;
    for (int j=1;j<=m;j++)
    {
        cin>>k[j];
        len+=k[j];
        if (k[j]==0)
            good++;
    }

    int ans=1e9;
    int r=1;


    for (int i=1;i<=n;i++)
    {
        while (r<=n && good!=m)
        {
            add(a[r]);
            r++;
        }
        if (good==m)
            ans=min(ans,r-i-len);
        dell(a[i]);

    }

    if (ans==1e9)
        cout<<-1; else
        cout<<ans;
}
/*
*/