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

const int N=2e5+10,M=1e6;
const double mtim=2.3;
ll n,a[N],pr[N];
int nt[M+10],m=1;
auto ss=chrono::system_clock::now();

double remain_time()
{
    auto en=chrono::system_clock::now();
    return mtim-(chrono::duration_cast<chrono::nanoseconds>(en-ss).count()*1e-9);
}

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
}

void sieve(int k)
{
    for (int i=2;i<=k;i++)
        if (!nt[i])
        {
            pr[m++]=i;
            for (int j=i;j<=k;j+=i) nt[j]=1;
        }
    m--;
}

int cal(ll x)
{
    ll res=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]<x) res+=x-a[i];
        else res+=min(a[i]%x,x-(a[i]%x));
        if (res>n) return n;
    }
    return res;
}


int rng(int x) { return Int(0,x-1); }

int ans;

set<ll> prime;

void update(ll x)
{
    for (int i=1;i<=m && pr[i]*pr[i]<=x;i++)
        if (x%pr[i]==0)
        {
            while (x%pr[i]==0) x/=pr[i];
            if (prime.count(pr[i])==0)
            {
                prime.insert(pr[i]);
                ans=min(ans,cal(pr[i]));
            }
        }
    if (x>1 && prime.count(x)==0)
    {
        prime.insert(x);
        ans=min(ans,cal(x));
    }
}

void process()
{
    random_shuffle(a+1,a+n+1,rng);
    sieve(M);
    ans=cal(2);
    prime.insert(2);
    for (int i=1;i<=ans;i++)
    {
        if (a[1]>i+1) update(a[1]-i);
        update(a[1]+i);
        if (remain_time()<=1.3) break;
    }
    for (int i=1;i<=n;i++)
    {
        update(a[i]);
        if (remain_time()<=0) break;
    }
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}