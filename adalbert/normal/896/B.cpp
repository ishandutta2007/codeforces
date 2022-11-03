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

string st1,st2,st3,st0;
int len[arr];

char getans(int x, int y)
{
    if (len[x]<y)
        return('.');
    if (x==0)
        return(st0[y-1]);

    if (y<=st1.size())
        return(st1[y-1]);
    y-=st1.size();
    if (y<=len[x-1])
        return(getans(x-1,y));
    y-=len[x-1];
    if (y<=st2.size())
        return(st2[y-1]);
    y-=st2.size();
    if (y<=len[x-1])
        return(getans(x-1,y));
    y-=len[x-1];

    return(st2[y-1]);
}

void vuv(int u)
{
    cout<<u<<'\n';
    fflush(stdout);
}

int a[10000];

signed main()
{
    int n,m,c;
    cin>>n>>m>>c;

    int l=1;
    int r=n;
    a[r+1]=1e18;
    for (int i=1;i<=m;i++)
    {
        int p;
        cin>>p;
        if (p>c/2)
        {
            if (p<=a[r+1])
            {
                a[r]=p;
                vuv(r);
                r--;
            } else
            {
                int now=r+1;
                while (a[now+1]<p)
                    now++;
                a[now]=p;
                vuv(now);
            }
        } else
        {
            if (p>=a[l-1])
            {
                a[l]=p;
                vuv(l);
                l++;
            } else
            {
                int now=l-1;
                while (a[now-1]>p)
                    now--;
                a[now]=p;
                vuv(now);
            }

        }


        if (l>r)
        {
            return(0);
        }
    }
}