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

    }

    for (int i=1;i<=min(n,len);i++)
    {
        cnt[a[i]]++;
    }

    bool ans=0;

    for (int i=len;i<=n;i++)
    {
        bool ch=1;
        for (int j=1;j<=m;j++)
            if (cnt[j]!=k[j])
            ch=0;
        if (ch)
            ans=1;
        cnt[a[i+1]]++;
        cnt[a[i-len+1]]--;
    }

    if (ans)
        cout<<"YES"; else
        cout<<"NO";
}
/*
*/