#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

struct rec { int x1,y1,x2,y2; };
rec a[N];
int n,check=1;

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
}

bool cmp1(rec t1,rec t2) {return t1.x1<t2.x1; }
bool cmp2(rec t1,rec t2) {return t1.y1<t2.y1; }

void solve(int l,int r)
{
    if (l==r) return;
    sort(a+l,a+r+1,cmp1);
    vector<int> can;
    for (int i=l;i<=r;i++) can.pb(a[i].x2);
    sort(all(can));
    int mid=l,val=0;
    for (int x : can)
    {
        while (mid<=r && a[mid].x1<x)
        {
            val=max(val,a[mid].x2);
            mid++;
        }
        if (mid>r || val<=x) break;
    }
    if (mid<=r)
    {
        solve(l,mid-1);
        solve(mid,r);
        return;
    }
    sort(a+l,a+r+1,cmp2);
    can.clear();
    for (int i=l;i<=r;i++) can.pb(a[i].y2);
    sort(all(can));
    mid=l,val=0;
    for (int y : can)
    {
        while (mid<=r && a[mid].y1<y)
        {
            val=max(val,a[mid].y2);
            mid++;
        }
        if (mid>r || val<=y) break;
    }
    if (mid<=r)
    {
        solve(l,mid-1);
        solve(mid,r);
        return;
    }
    check=0;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    solve(1,n);
    if (check) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}