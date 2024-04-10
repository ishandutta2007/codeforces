#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

struct data
{
    double x, y, r;
};

bool comp(data &d1, data &d2)
{
    return d1.r<d2.r;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int n;
data a[N], l[N], r[N];
double ans=0;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].r;
    sort(a+1, a+n+1, comp);
    int lsz=0, rsz=0;
    for(int i=n;i>=1;i--)
    {
        int cnt=0;
        for(int j=1;j<=lsz;j++)
        {
            if(dist(a[i].x, a[i].y, l[j].x, l[j].y)<=abs(a[i].r-l[j].r))
                cnt++;
        }
        if(cnt%2==0)
        {
            l[++lsz]=a[i];
            ans+=acos(-1) * a[i].r * a[i].r; 
            continue;
        }
        cnt=0;
        for(int j=1;j<=rsz;j++)
        {
            if(dist(a[i].x, a[i].y, r[j].x, r[j].y)<=abs(a[i].r-r[j].r))
                cnt++;
        }
        r[++rsz]=a[i];
        if(cnt%2==0)
            ans+=acos(-1) * a[i].r * a[i].r;
        else
            ans-=acos(-1) * a[i].r * a[i].r;
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}