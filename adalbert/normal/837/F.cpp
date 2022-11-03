#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define y1 drfijortjubo
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=2e5+10;

struct matrix
{
    ll a[16][16];
    matrix(const matrix& cp)
    {
        for (int i=1;i<=15;i++)
            for (int j=1;j<=15;j++)
            this -> a[i][j]=cp.a[i][j];
    }
    matrix()
    {

    }
};

matrix mult(matrix &a, matrix &b)
{
    matrix c;
    for (int i=1;i<=15;i++)
        for (int j=1;j<=15;j++)
        {
            ll now=0;
            for (int l=1;l<=15;l++)
            {
                if (a.a[i][l]==0) continue;
                ll to=a.a[i][l]*b.a[l][j];
                if (to/a.a[i][l]!=b.a[l][j])
                        to=1e18+1;
                if (now>1e18 || to>1e18)
                    now=1e18+1; else
                    now=min(now+to,ll(1e18)+1);
            }
            c.a[i][j]=now;
        }

    return(c);
}

matrix pow(matrix &a, ll step)
{
    if (step==1) return(a);
    if (step%2==0)
    {
        matrix now=pow(a,step/2);
        return(mult(now,now));
    } else
    {
        matrix now=pow(a,step-1);

        return(mult(a,now));
    }
}

vector<ll> vec;
ll k;

void easy_solve()
{
    ll mx=0;
    for (int i=0;i<vec.size();i++)
        mx=max(mx,vec[i]);
    ll res=0;
    while (mx<k)
    {
        res++;
        for (int i=1;i<vec.size();i++)
        {
            vec[i]+=vec[i-1];
            mx=max(mx,vec[i]);
        }
    }
    cout<<res<<'\n';
}

bool check(ll u)
{
    matrix m;
    for (int i=1;i<=15;i++)
        for (int j=1;j<=15;j++)
        m.a[i][j]=(j>=i);
    m=pow(m,u);
    for (int i=0;i<vec.size();i++)
    {
        ll now=0;
        for (int j=0;j<vec.size();j++)
        {
            if (m.a[j+1][i+1]==0) continue;
            ll to=m.a[j+1][i+1]*vec[j];
                if (to/m.a[j+1][i+1]!=vec[j])
                        to=1e18+1;
            if (now>1e18 || to>1e18)
                    now=1e18+1; else
                    now=min(now+to,ll(1e18)+1);
            //if (now<0) cout<<'!';
        }
        if (now>=k) return(1);
    }
    return(0);
}

void smart_solve()
{
    for (int i=0;i<vec.size();i++)
        if (vec[i]>=k)
    {
        cout<<0;
        exit(0);
    }
    ll l=1;
    ll r=1e18;
    while (r-l>1)
    {
        ll d=(r+l)/2;
        if (check(d)) r=d; else l=d;
    }
    if (check(l)) cout<<l<<'\n'; else
        cout<<r<<'\n';
}

///-----------------------------------------------------------------------///
signed main()
{
    int n;
    cin>>n>>k;
    while (n--)
    {
        ll a;
        cin>>a;
        vec.pb(a);
    }
    reverse(vec.begin(),vec.end());
    while (vec.back()==0) vec.pop_back();
    reverse(vec.begin(),vec.end());

    if (vec.size()>15)
        easy_solve(); else
        smart_solve();
}