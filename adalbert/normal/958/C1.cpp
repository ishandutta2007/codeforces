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

int pred[arr],nxt[arr],a[arr];

signed main()
{
    int n,p;
    cin>>n>>p;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
        pred[i]=(pred[i-1]+a[i])%p;

    for (int i=n;i>=1;i--)
        nxt[i]=(nxt[i+1]+a[i])%p;

    int ans=0;

    for (int i=1;i<n;i++)
    {
        ans=max(ans,pred[i]+nxt[i+1]);
    }

    cout<<ans;
}
/*
*/