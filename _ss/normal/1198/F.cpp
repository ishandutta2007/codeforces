#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()

namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) { return uniform_int_distribution<ll> (l,r)(mt); }
}

using namespace myrand;

const int N=1e5+10;
const double mtim=0.4;
int n,a[N],p[N],ans[N];
auto ss=chrono::system_clock::now();

double remain_time()
{
    auto en=chrono::system_clock::now();
    return mtim-(chrono::duration_cast<chrono::nanoseconds>(en-ss).count()*1e-9);
}

void read()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
}

int gcd(int t1,int t2)
{
    while (t2)
    {
        int tmp=t1%t2;
        t1=t2;
        t2=tmp;
    }
    return t1;
}

vector<int> vt1,vt2;

bool minimize()
{
    if (vt1.size()==1) return false;
    vector<int> vt;
    vt.pb(vt1.back());
    int di=a[vt.back()];
    for (int i=0;i<(int)vt1.size()-1;i++)
        if (a[vt1[i]]%di==0) vt2.pb(vt1[i]);
        else
        {
            di=gcd(di,a[vt1[i]]);
            vt.pb(vt1[i]);
        }
    if (vt1.size()==vt.size()) return false;
    vt1=vt;
    return true;
}

bool check()
{
    vt1.clear();
    vt2.clear();
    vt1.pb(p[1]);
    int di=a[p[1]];
    for (int i=2;i<=n;i++)
        if (a[p[i]]%di==0) vt2.pb(p[i]);
        else
        {
            di=gcd(di,a[p[i]]);
            vt1.pb(p[i]);
        }
    bool flag=true;
    while (flag) flag=minimize();
    if (vt2.empty()) return false;
    di=a[vt2[0]];
    for (int x : vt2) di=gcd(a[x],di);
    return (di==1);
}

int rng(int x) { return Int(0,x-1); }

void process()
{
    int di=0;
    for (int i=1;i<=n;i++) di=gcd(a[i],di);
    if (di>1)
    {
        cout<<"NO";
        return;
    }
    for (int i=1;i<=n;i++) p[i]=i;
    while (remain_time()>0)
    {
        random_shuffle(p+1,p+n+1,rng);
        if (check())
        {
            for (int x : vt1) ans[x]=1;
            for (int x : vt2) ans[x]=2;
            cout<<"YES\n";
            for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
            return;
        }
    }
    cout<<"NO";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cout.tie(0);
    read();
    process();
    return 0;
}