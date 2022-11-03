#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int bigarr=1e6+100;
const int arr=2e5+100;

const int bs=150;

pair<int,int> go[arr];
int n,m;
int a[arr];

void resolve(int u)
{
    int left=u*bs;
    int right=u*bs+bs-1;
    right=min(right,n);

    for (int i=right;i>=left;i--)
    {
        if (i+a[i]>right)
        {
            go[i].fir=i+a[i];
            go[i].sec=1;
        } else
        {
            go[i].fir=go[i+a[i]].fir;
            go[i].sec=go[i+a[i]].sec+1;
        }
    }
}

///-----------------------------------------------------------------------///
signed main()
{
    fast;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=0;i<=n/bs;i++)
        resolve(i);

    while (m--)
    {
        int type;
        cin>>type;
        if (type==0)
        {
            int c,b;
            cin>>c>>b;
            a[c]=b;
            resolve(c/bs);
        } else
        {
            int p;
            cin>>p;
            int ans=0;
            int last=p;
            while (p<=n)
            {
                last=p;
                ans+=go[p].sec;
                p=go[p].fir;
            }

            while (last+a[last]<=n)
                last+=a[last];

            cout<<last<<' '<<ans<<'\n';
        }
    }

}
/*
10 1
5 1 2 4 6 1 3 8 10 3
1 1
*/