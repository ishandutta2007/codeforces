#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
pii a[N][10];

int stg(pii p1,pii p2,pii p3)
{
    return (p2.fi-p1.fi)*(p2.se+p1.se)+(p3.fi-p2.fi)*(p3.se+p2.se)+(p1.fi-p3.fi)*(p1.se+p3.se);
}

bool inside(int id,pii x)
{
    int s=0;
    for (int i=1;i<=4;i++) s+=(a[id][i+1].fi-a[id][i].fi)*(a[id][i+1].se+a[id][i].se);
    s=abs(s);
    for (int i=1;i<=4;i++) s-=abs(stg(a[id][i],a[id][i+1],x));
    return (s==0);
}

bool inter(pii p1,pii p2,pii p3,pii p4)
{
    return (stg(p1,p3,p2)*stg(p1,p4,p2)<=0 && stg(p3,p1,p4)*stg(p3,p2,p4)<=0);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=2;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=4;j++) cin>>a[i][j].fi>>a[i][j].se;
    int check=0;
    a[1][5]=a[1][1];
    a[2][5]=a[2][1];
    for (int i=1;i<=4;i++)
        if (inside(1,a[2][i]) || inside(2,a[1][i])) check=1;
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
        if (inter(a[1][i],a[1][i+1],a[2][j],a[2][j+1])) check=1;
    if (check) cout<<"YES";
    else cout<<"NO";
    return 0;
}