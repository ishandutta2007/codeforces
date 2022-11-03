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

const int arr=3e5+100;
const int base=31;

int cnt[arr],now[arr],need[arr],can[arr];

int w,l;

bool check(int u)
{
    for (int i=1;i<=w;i++)
        can[i]=cnt[i];
    for (int i=0;i<=w;i++)
        need[i]=0;
    can[w]=1e12;
    need[0]=u;

    int last=0;

    for (int i=1;i<=w;i++)
    {
        while (can[i]!=0 && last!=i)
        {
            if (abs(last-i)>l)
                return(0);
            int now=min(can[i],need[last]);
            need[last]-=now;
            can[i]-=now;
            need[i]+=now;
            while (need[last]==0)
                last++;
        }
    }

    return(1);
}

signed main()
{

    cin>>w>>l;

    for (int i=1;i<w;i++)
        cin>>cnt[i];

    int l=0;
    int r=1e12;

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d))
            l=d; else
            r=d;
    }
    cout<<l;
}