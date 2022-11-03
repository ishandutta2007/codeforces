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

int v[8*arr];
int a[arr];

void add(int i, int l, int r, int x)
{
    if (l==r)
    {
        v[i]++;
        return;
    }

    int d=(l+r)/2;

    if (x<=d)
        add(i*2,l,d,x); else
        add(i*2+1,d+1,r,x);
    v[i]=v[i*2]+v[i*2+1];
}

int get(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
        return(v[i]);
    if (tl>r || tr<l)
        return(0);

    int d=(tl+tr)/2;

    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));
}

signed main()
{
    int n,k,d;
    cin>>n>>k>>d;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);

    int left=1;

    add(1,0,n,0);

    for (int i=1;i<=n;i++)
    {
        while (a[i]-a[left]>d)
            left++;
        int right=i-k;
        int now=get(1,0,n,left-1,right);
        if (now)
            add(1,0,n,i);
    }

    if (get(1,0,n,n,n))
        cout<<"YES"; else
        cout<<"NO";
}