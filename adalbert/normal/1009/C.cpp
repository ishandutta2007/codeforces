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

signed main()
{
    int n,m;
    cin>>n>>m;

    int ans=0;

    int c1=0;

    for (int i=1;i<=n;i++)
        c1+=abs(i-1);

    int c2=0;

    for (int i=1;i<=n;i++)
        c2+=abs(i-(n+1)/2);

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        ans+=a*n;

        ans+=max(b*c1,b*c2);
    }

    cout<<fixed<<setprecision(9)<<ld(ans)/ld(n);
}
/*
*/