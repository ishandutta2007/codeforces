#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
int n;
double a[maxn],b[maxn],m;

double cal(double x, double t)
{
    return x/(t-1);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++)
        if (a[i]==1 || b[i]==1)
        {
            cout<<-1;
            return 0;
        }
    vector<double> c;
    c.pb(b[1]);
    for (int i=n;i>1;i--)
    {
        c.pb(a[i]);
        c.pb(b[i]);
    }
    c.pb(a[1]);
    double tmp=m;
    for (int i=0;i<(int)c.size();i++) m+=cal(m,c[i]);
    printf("%.10f",m-tmp);
    return 0;
}