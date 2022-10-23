#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=2e5+1,mod=1e9+7,inf=1e9;
struct ds
{
    int x1,y1,x2,y2;
};
int n;
ds a[maxn],pr[maxn],su[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
    pr[0]={-inf,-inf,inf,inf};
    su[n+1]=pr[0];
    for (int i=1;i<=n;i++)
    {
        pr[i].x1=max(pr[i-1].x1,a[i].x1);
        pr[i].y1=max(pr[i-1].y1,a[i].y1);
        pr[i].x2=min(pr[i-1].x2,a[i].x2);
        pr[i].y2=min(pr[i-1].y2,a[i].y2);
    }
    for (int i=n;i;i--)
    {
        su[i].x1=max(su[i+1].x1,a[i].x1);
        su[i].y1=max(su[i+1].y1,a[i].y1);
        su[i].x2=min(su[i+1].x2,a[i].x2);
        su[i].y2=min(su[i+1].y2,a[i].y2);
    }
    int x1,y1,x2,y2;
    for (int i=1;i<=n;i++)
    {
        x1=max(pr[i-1].x1,su[i+1].x1);
        y1=max(pr[i-1].y1,su[i+1].y1);
        x2=min(pr[i-1].x2,su[i+1].x2);
        y2=min(pr[i-1].y2,su[i+1].y2);
        if (x1<=x2 && y1<=y2)
        {
            cout<<x1<<" "<<y1;
            return 0;
        }
    }
    return 0;
}