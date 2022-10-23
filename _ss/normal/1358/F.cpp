#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=2e5+10,lim=2e5;

ll a[N],b[N],n,a2[N];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
}

bool same()
{
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]) return false;
    return true;
}

bool same2()
{
    for (int i=1;i<=n;i++)
        if (a2[i]!=b[i]) return false;
    return true;
}

void rev()
{
    for (int i=1;i<=n/2;i++) swap(b[i],b[n-i+1]);
}

void ps()
{
    for (int i=n;i;i--) b[i]-=b[i-1];
}

int check()
{
    int delta;
    if (b[1]==b[2]) return 0;
    else if (b[1]<b[2]) delta=1;
    else delta=-1;
    for (int i=1;i<n;i++)
        if ((b[i+1]-b[i])*delta<=0) return 0;
    return delta;
}

void sub1()
{
    vector<int> ans;
    ll d=0,mn=min(a[1],a[2]),mx=max(a[1],a[2]);
    while (true)
    {
        if (b[1]==a[1] && b[2]==a[2]) break;
        if (b[1]==a[2] && b[2]==a[1])
        {
            ans.pb(0);
            break;
        }
        if (b[1]<=0 || b[2]<=0)
        {
            cout<<"IMPOSSIBLE";
            return;
        }
        if (b[1]>b[2]) ans.pb(0),swap(b[1],b[2]);
        ll sl;
        if (b[1]==mn && (b[2]-mx)%mn==0)
        {
            sl=(b[2]-mx)/mn;
            b[2]=mx;
        }
        else sl=b[2]/b[1],b[2]%=b[1];
        d+=sl;
        if (d<=lim)
            for (int i=1;i<=sl;i++) ans.pb(1);
    }
    if (d>lim)
    {
        cout<<"BIG\n"<<d;
        return;
    }
    cout<<"SMALL\n"<<ans.size()<<"\n";
    for (int i=(int)ans.size()-1;i>=0;i--)
        if (ans[i]) cout<<"P";
        else cout<<"R";
}

void sub2()
{
    for (int i=1;i<=n;i++) a2[i]=a[n-i+1];
    vector<int> ans;
    int d=0;
    while (true)
    {
        if (same()) break;
        if (same2())
        {
            ans.pb(0);
            break;
        }
        int v=check();
        if (v==0)
        {
            cout<<"IMPOSSIBLE";
            return;
        }
        if (v==-1) ans.pb(0),rev();
        ps();
        ans.pb(1);
        d++;
    }
    if (d>2e5)
    {
        cout<<"BIG\n"<<d;
        return;
    }
    cout<<"SMALL\n"<<ans.size()<<"\n";
    for (int i=(int)ans.size()-1;i>=0;i--)
        if (ans[i]) cout<<"P";
        else cout<<"R";
}

void process()
{
    if (n==1)
    {
        if (a[1]==b[1]) cout<<"SMALL\n0";
        else cout<<"IMPOSSIBLE";
        return;
    }
    if (n==2) sub1();
    else sub2();
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