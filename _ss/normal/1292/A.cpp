#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;

int a[N],n,q,sta[3][N];

bool check(int x)
{
    return (sta[1][x] || sta[1][x+1]) && (sta[2][x] || sta[2][x+1]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    int cnt=0;
    for (int i=1,x,y;i<=q;i++)
    {
        cin>>x>>y;
        sta[x][y]^=1;
        if (a[y])
        {
            if (!check(y)) cnt--,a[y]=0;
        }
        else
        {
            if (check(y)) cnt++,a[y]=1;
        }
        if (a[y-1])
        {
            if (!check(y-1)) cnt--,a[y-1]=0;
        }
        else
        {
            if (check(y-1)) cnt++,a[y-1]=1;
        }
        if (cnt==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}