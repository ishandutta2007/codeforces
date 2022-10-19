#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl;

void q1()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    Sort(a);

    int ans=0;
    for(int i=1;i<n;i++)
    {
        int t=a[i];
        a[i]=a[i-1]+1;
        ans+=a[i]-t;
    }
    cout << ans  << endl;

    return;
}

void q2()
{
    int n , m;
    cin >> n >> m;

    deque<pii> d(n);
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        d[i]=Mp(t,i+1);
    }

    int ans=0;
    while(d.size()!=0)
    {
        pii p=d[0];
        d.pop_front();

        if(p.X>m)
        {
            d.push_back(Mp(p.X-m,p.Y));
        }
        ans=p.Y;
        if(d.size()==0)
        {
            break;
        }
    }

    cout << ans << endl;
}

void q3()
{
    ll n, ans=0;
    cin >> n;

    ll j=9;
    for(ll i=1;n!=0;i++)
    {
        ll t=min(n,j);
        ans+=t*i;

        n-=t;
        j*=10;
    }
    cout << ans << endl;
}

int main()
{
    q2();
    return 0;
}