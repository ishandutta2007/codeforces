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
const int arr=2e5;

int a[arr],aa[arr];
int n,d,b;

bool check(int u)
{
    for (int i=1;i<=n;i++)
        a[i]=aa[i];
    int pluss=0;
    int uu=u;
    int start=1;
    int mid=n/2+n%2;
    while (1)
    {
        if (a[start]>=b)
            pluss+=a[start]-b; else
            if (uu)
            uu--,pluss+=a[start]; else break;
        start++;
        if (start>mid)
            break;
    }

    int last=start;

    pluss+=a[start];
    for (int i=start;i<=mid;i++)
    {
        while (last+1<=min(i+i*d,n))
        {
            last++;
            pluss+=a[last];
            a[last]=0;
        }
        if (pluss<b)
            return(0);
        pluss-=b;
    }
    for (int i=1;i<=n;i++)
        a[i]=aa[i];
    reverse(a+1,a+1+n);
    pluss=0;
    uu=u;
    start=1;
    mid=n/2;
    while (1)
    {
        if (a[start]>=b)
            pluss+=a[start]-b; else
            if (uu)
            uu--,pluss+=a[start]; else break;
        start++;
        if (start>mid)
            break;
    }

    last=start;
    pluss+=a[start];
    for (int i=start;i<=mid;i++)
    {
        while (last+1<=min(i+i*d,n))
        {
            last++;
            pluss+=a[last];
            a[last]=0;
        }
        if (pluss<b)
            return(0);
        pluss-=b;
    }
    return(1);
}

signed main()
{
    cin>>n>>d>>b;

    for (int i=1;i<=n;i++)
        cin>>aa[i];

    int l=0;
    int r=n;

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d))
            r=d; else l=d;
    }

    if (check(l))
        cout<<l; else
        cout<<r;
}
/*
100 2 25
23 47 16 0 81 70 6 4 31 26 56 58 33 34 23 141 24 18 7 7 2 13 15 8 34 115 7 30 6 7 14 62 3 0 7 73 4 7 5 35 17 26 34 33 12 3 23 27 3 40 2 5 10 10 4 56 50 36 4 14 22 17 7 13 22 85 30 7 10 28 60 35 3 27 0 3 7 52 12 10 74 14 56 54 17 1 50 11 23 2 71 31 11 5 9 10 13 7 16 14

*/