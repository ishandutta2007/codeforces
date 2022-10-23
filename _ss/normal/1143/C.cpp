#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
int p[maxn],c[maxn],d[maxn];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) d[i]=1;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i]>>c[i];
        if (p[i]>0) d[p[i]]*=c[i];
    }
    int kt=0;
    for (int i=1;i<=n;i++)
        if (d[i] && c[i] && p[i]>0) cout<<i<<" ",kt++;
    if (!kt) cout<<-1;
    return 0;
}