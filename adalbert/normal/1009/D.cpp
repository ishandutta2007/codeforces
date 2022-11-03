#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b)
        a%=b; else
        b%=a;
    return(a+b);
}

signed main()
{
    int n,m;
    cin>>n>>m;

    if (m<n-1)
    {
        cout<<"Impossible";
        return(0);
    }

    vector<pair<int,int> > ans;

    for (int i=1;i<=n && m!=0;i++)
        for (int j=i+1;j<=n && m!=0;j++)
        if (nsd(i,j)==1)
    {
        ans.pb({i,j});
        m--;
    }

    if (m!=0)
    {
        cout<<"Impossible";
        return(0);
    }

    cout<<"Possible\n";
    for (auto i:ans)
        cout<<i.fir<<' '<<i.sec<<'\n';
}
/*
*/