#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll inf=1e10,mpow=33,N=1e5,M=1e3;
vector<int> prime;
int nt[N+10];

void sieve()
{
    for (int i=2;i<=N;i++)
        if (!nt[i])
        {
            prime.pb(i);
            for (int j=i*2;j<=N;j+=i) nt[j]=1;
        }
}

string tostring(ll x)
{
    string res;
    while (x)
    {
        char ch=(char)(x%10+48);
        res=ch+res;
        x/=10;
    }
    return res;
}

ll power(ll x,int h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1)
        {
            if (res>inf/x) return inf;
            res=res*x;
        }
        if (h==1) return res;
        if (x>inf/x) return inf;
        x=x*x;
    }
    return res;
}

int cb(ll x,int h)
{
    int l=2,r=N;
    while (l<=r)
    {
        int mid=(l+r)/2;
        ll tmp=power(mid,h);
        if (tmp>x) r=mid-1;
        else if (tmp<x) l=mid+1;
        else return mid;
    }
    return -1;
}

string best_rep1(ll x)
{
    string res=tostring(x);
    for (int i=2;i<=mpow;i++)
    {
        int tmp=cb(x,i);
        if (tmp==-1) continue;
        string can=tostring(tmp)+"^"+tostring(i);
        if (can.length()<res.length()) res=can;
    }
    return res;
}

map<ll,string> in_num3,in_num4;

vector<ll> divi(ll x)
{
    vector<ll> res;
    res.pb(1);
    for (int p : prime)
        if (x%p==0)
        {
            ll bonus=1;
            while (x%p==0)
            {
                x/=p;
                bonus*=p;
                for (ll k : res)
                {
                    if (k%p==0) break;
                    res.pb(k*bonus);
                }
            }
        }
    if (x>1)
    {
        for (ll k : res)
        {
            if (k%x==0) break;
            res.pb(k*x);
        }
    }
    return res;
}

string best_rep2(ll x,int mlen)
{
    string res=best_rep1(x);
    vector<ll> divisor=divi(x);
    sort(all(divisor));
    for (ll k : divisor)
    {
        if (x/k<k) break;
        string can=best_rep1(k)+"*"+best_rep1(x/k);
        if (can.length()<res.length()) res=can;
    }
    if (mlen==9)
    {
        for (int i=2;i<=9;i++)
            for (int j=2;j<=9;j++)
                for (int t=2;t<=9;t++)
                {
                    ll tmp=power(i,j)*t;
                    string st=in_num3[x/tmp];
                    if (x%tmp==0 && st!="")
                    {
                        string can=tostring(i)+"^"+tostring(j)+"*"+st+"*"+tostring(t);
                        if (can.length()<res.length()) res=can;
                    }
                }
    }
    return res;
}

string solve(ll n)
{
    if (n==1e10) return "10^10";
    for (int i=2;i<=9;i++)
        for (int j=2;j<=9;j++) in_num3[power(i,j)]=tostring(i)+"^"+tostring(j);
    string res=best_rep2(n,9);
    ll R=n,L=max((ll)1,n-M+1);
    for (ll i=L;i<R;i++)
    {
        string can=tostring(n-i)+"+";
        can+=best_rep2(i,9-(int)can.length());
        if (can.length()<res.length()) res=can;
    }
    for (int i=2;i<=99;i++)
        for (int j=2;j<=mpow;j++)
        {
            ll tmp=power(i,j);
            if (tmp>=n) continue;
            in_num4[tmp]=tostring(i)+"^"+tostring(j);
            string can=tostring(i)+"^"+tostring(j)+"+"+tostring(n-tmp);
            if (can.length()<res.length()) res=can;
        }
    for (int i=2;i<=99;i++)
        for (int j=2;j<=mpow;j++)
        {
            ll tmp=power(i,j);
            if (tmp>=n) continue;
            string st=in_num4[n-tmp];
            if (st!="")
            {
                string can=tostring(i)+"^"+tostring(j)+"+"+st;
                if (can.length()<res.length()) res=can;
            }
        }
    for (int i=2;i<=9;i++)
        for (int j=2;j<=9;j++)
        {
            for (int t=2;t<=9;t++)
            {
                ll tmp=power(i,j)+t;
                string st=in_num3[n-tmp];
                if (st!="")
                {
                    string can=tostring(i)+"^"+tostring(j)+"+"+st+"+"+tostring(t);
                    if (can.length()<res.length()) res=can;
                }
            }
            ll tmp=power(i,j);
            if (tmp>=n) continue;
            string can=tostring(i)+"^"+tostring(j)+"+";
            can+=best_rep2(n-tmp,9-can.length());
            if (can.length()<res.length()) res=can;
        }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    sieve();
    cout<<solve(n);
    return 0;
}