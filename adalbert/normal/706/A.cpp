#include <bits/stdc++.h>
using namespace std;
int rdn(int y, int m, int d)
{
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
long long x2,x3,x4,y2,y3,y4,kf1,kf2,ans,n,dp[1000][1000],q,m,k,h1,m1,h2,m2,t1,t2,tep;
vector<pair<long long ,long long> > vec;
string st,s;
double a,b,x,y,mn,v;
/// *** program *** ///
int main()
{
        cin>>a>>b;
        cin>>n;
        mn=100000000000000;
        for (int i=1;i<=n;i++)
        {
            cin>>x>>y>>v;
            mn=min(mn,(sqrt((x-a)*(x-a)+(y-b)*(y-b)))/v);
        }
        cout << fixed << setprecision(19) << mn;
}