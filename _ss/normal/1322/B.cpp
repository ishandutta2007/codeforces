#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10,mb=25;
int a[N],n;

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}

int find_vt(int x,vector<int> &vt)
{
    int tmp=upper_bound(all(vt),x)-vt.begin();
    return tmp;
}

int check(int x)
{
    vector<int> vt1,vt2;
    for (int i=1;i<=n;i++)
        if ((a[i]>>x)&1) vt1.pb(a[i] & ((1<<x)-1));
        else vt2.pb(a[i] & ((1<<x)-1));
    sort(all(vt1));
    sort(all(vt2));
    int cnt=0;
    for (int h : vt1)
    {
        cnt+=(int)vt1.size()-find_vt((1<<x)-h-1,vt1);
        if (h+h>=(1<<x)) cnt--;
    }
    for (int h : vt2)
    {
        cnt+=(int)vt2.size()-find_vt((1<<x)-h-1,vt2);
        if (h+h>=(1<<x)) cnt--;
    }
    cnt/=2;
    for (int h : vt1) cnt+=find_vt((1<<x)-h-1,vt2);
    return (cnt&1);
}

void process()
{
    int res=0;
    for (int i=0;i<mb;i++)
        if (check(i)) res+=(1<<i);
    cout<<res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}