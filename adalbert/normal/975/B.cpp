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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int a[100],b[100];

signed main()
{
    int n;
    n=14;
    for (int i=0;i<n;i++)
        cin>>a[i];

    int ans=0;

    for (int start=0;start<n;start++)
    {
        for (int i=0;i<n;i++)
            b[i]=a[i];
        b[start]=0;
        int all=a[start]/14;
        int sp=a[start]%14;

        for (int i=start+1;i<=start+14;i++)
        {
            b[i%14]+=all;
            if (i-start<=sp)
                b[i%14]++;
        }

        int now=0;
        for (int i=0;i<n;i++)
            if (b[i]%2==0)
            now+=b[i];

        ans=max(ans,now);
    }

    cout<<ans;
}