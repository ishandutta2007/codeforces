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

int a[arr],b[arr],c[arr];

map<pair<int,int>,int > mp;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b)
            a%=b; else
            b%=a;
    }

    return(a+b);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch>>a[i]>>ch>>b[i]>>ch>>ch>>c[i];

        a[i]+=b[i];
        int ns=nsd(a[i],c[i]);
        a[i]/=ns;
        c[i]/=ns;
        mp[{a[i],c[i]}]++;
    }

    for (int i=1;i<=n;i++)
        cout<<mp[{a[i],c[i]}]<<' ';
}
/*
*/